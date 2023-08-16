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

        [[nodiscard]] pointer allocate(size_type n)
        {
            pointer ptr{new(memory_pool) T}  
        }
        void deallocate(pointer p, size_type n) noexcept;

        template <typename U>
        constexpr allocator(const allocator<U>&) noexcept {}
        
        // reference operator=(const allocator& other);

        // allocator(allocator&& other);
        // reference operator=(allocator&& other);

        

    private:
        static uint8_t memory_pool[Amount*sizeof(T)];
        
    };
    template <typename T, typename U>
    bool operator==(const allocator<T>&, const allocator<U>&)
    {
        return true;
    }

    template <typename T, typename U>
    bool operator!=(const allocator<T>&, const allocator<U>&)
    {
        return false;
    }
};


#endif
