#ifndef MY_ALLOCATOR_HPP
#define MY_ALLOCATOR_HPP

#include <cstddef>
#include <cstdint>
#include <limits>

namespace oskar
{

    template <typename T, std::size_t Amount>
    class allocator
    {
    public:
        using pointer = T*;
        using const_pointer = const T*;
        using value_type = T;
        using reference = T&;
        using size_type = std::size_t;
        using difference_type = std::ptrdiff_t;

        reference operator*();       

        allocator() = default;

        [[nodiscard]] pointer allocate(size_type)
        {
            if (Amount > 0)
            {
                return new(memory_pool) T{};
            }
            else
            {
                return nullptr;
            }
        }
        
        void deallocate(pointer p, size_type) noexcept
        {
            if (Amount > 0)
            {
                p->~T;
            }
        }

        template <typename U>
        constexpr allocator(const allocator<U, Amount>&) noexcept {}
        

    private:
        static inline uint8_t memory_pool[Amount*sizeof(T)];
        
    };
 
   
    template <typename T, std::size_t TAmount, typename U, std::size_t UAmount>
    bool operator==(const allocator<T, TAmount>&, const allocator<U, UAmount>&)
    {
        return true;
    }

   
    
    template <typename T, std::size_t TAmount, typename U, std::size_t UAmount>
    bool operator!=(const allocator<T, TAmount>&, const allocator<U, UAmount>&)
    {
        return false;
    }
    
};


#endif
