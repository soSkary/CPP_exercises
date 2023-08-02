#ifndef HEAP_ARRAY_HPP
#define HEAP_ARRAY_HPP

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <initializer_list>
#include <limits>
#include <stdexcept>

namespace oskar
{
    template <typename T>
    class heap_array
    {
    public:
        //types
        using value_type = T;
        using reference = T&;
        using const_reference = const T&;
        using iterator = T*;
        using const_iterator = const T*;
        using difference_type = std::ptrdiff_t;
        using size_type = std::size_t;

        //constructors
        heap_array();
        heap_array(size_type sz);
        heap_array(std::initializer_list<T> init_list);
        heap_array(const heap_array& other);
        heap_array(heap_array&& other);
        //assignment operators /*These should call the constructors by default*/
        heap_array& operator=(const heap_array& other);
        heap_array& operator=(heap_array&& other);
        //destructor
        ~heap_array();

        //iteration functions
        iterator begin();
        iterator end();
        const_iterator begin() const;
        const_iterator end()  const;
        const_iterator cbegin() const;
        const_iterator cend() const;

        //size functions
        size_type size() const;
        size_type capacity() const;
        size_type max_size() const { return std::numeric_limits<size_type>::max(); }
        bool empty() const;
        void resize(size_type new_size);
        void reserve(size_type new_total);

        //member access functions
        T* data() { return container_front; }
        T& at(const size_type index);
        T& operator[](const size_type index) { return *(container_front + index); }

        void push_back(const T& value);
        
        void swap(heap_array& other);

        friend std::ostream& operator<<<T>(std::ostream& out, const heap_array& ha);

    private:
        //three pointers: first element, capacity and first empty not containing a value
        // cf*____fe* _ _ _ _ cb*

        T* container_front;
        T* container_back;
        T* first_empty;
    };

    //default constructor
    template <typename T>
    heap_array<T>::heap_array()
        : container_front{ nullptr },
        container_back{ nullptr },
        first_empty{ nullptr }
    {}

    //construct to size
    template <typename T>
    heap_array<T>::heap_array(size_type sz)
        : container_front{ new T[sz] },
        container_back{ container_front + sz-1},
        first_empty{ container_front }
    {}

    //list_initializer constructor
    template <typename T>
    heap_array<T>::heap_array(std::initializer_list<T> init_list)
        : container_front{ new T[init_list.size()] },
        container_back{ container_front + init_list.size() - 1 },
        first_empty{ container_front }
    {
        for (auto& element : init_list)
        {
            *first_empty = std::move(element);
            ++first_empty;
        }
    }

    //copy constructor
    template <typename T>
    heap_array<T>::heap_array(const heap_array& other)
        : container_front{ new T[other.capacity()] },
        container_back{ container_front + other.capacity() },
        first_empty{ container_front }
    {
        for (const auto& element : other)
        {
            *first_empty = element;
            ++first_empty;
        }
    }

    //move constructor
    template <typename T>
    heap_array<T>::heap_array(heap_array&& other)
        : container_front{ other.container_front },
        container_back{ other.container_back },
        first_empty{ other.first_empty }
    {
        other.container_front = nullptr;
        other.container_back = nullptr;
        other.first_empty = nullptr;
    }

    //destructor
    template <typename T>
    heap_array<T>::~heap_array()
    {
        if (!empty())
            delete[] container_front;
    }

    //copy assignment operator
    template <typename T>
    heap_array<T>& heap_array<T>::operator=(const heap_array& other)
    {
        heap_array<T> temp{ other };
        this->swap( temp );
        return *this;
    }

    //move assignment operator
    template <typename T>
    heap_array<T>& heap_array<T>::operator=(heap_array&& other)
    {
        container_front = std::exchange(other.container_front, nullptr);
        container_back = std::exchange(other.container_back, nullptr);
        first_empty = std::exchange(other.first_empty, nullptr);

        return *this;
    }

    /*********************/
    /*Iteration functions*/
    /*********************/
    template <typename T>
    heap_array<T>::iterator heap_array<T>::begin()
    {
        return container_front;
    }

    template <typename T>
    heap_array<T>::iterator heap_array<T>::end()
    {
        return first_empty;
    }

    template <typename T>
    heap_array<T>::const_iterator heap_array<T>::begin()const
    {
        return container_front;
    }

    template <typename T>
    heap_array<T>::const_iterator heap_array<T>::end()const
    {
        return first_empty;
    }

    template <typename T>
    heap_array<T>::const_iterator heap_array<T>::cbegin()const
    {
        return const_cast<const_iterator>(begin());
    }

    template <typename T>
    heap_array<T>::const_iterator heap_array<T>::cend()const
    {
        return const_cast<const_iterator>(end());
    }

    /****************/
    /*Size functions*/
    /****************/
    template <typename T>
    heap_array<T>::size_type heap_array<T>::size() const
    {
        if (empty())
            return 0;

        return static_cast<size_type>(first_empty - container_front);
    }

    template <typename T>
    heap_array<T>::size_type heap_array<T>::capacity() const
    {
        if (empty())
            return 0;
        return static_cast<size_type>(container_back + 1 - container_front);
    }
    
    template <typename T>
    bool heap_array<T>::empty() const
    {
        if (container_front == nullptr || container_back == nullptr || first_empty == nullptr)
        {
            return true;
        }

        return false;
    }

    template <typename T>
    void heap_array<T>::resize(size_type new_size)
    {
        //Check if new_size is within current capacity
        if (new_size <= capacity())
        {
            first_empty = container_front + new_size;
            return;
        }
        //if not, create new array in heap, move the current contents, and delete old memory-allocation
        T* new_array{ new T[new_size + (new_size/2)] };

        T* new_last_value{ new_array };
        for (auto& element : *this)
        {
            *new_last_value = element;
            ++new_last_value;
        }
        delete[] container_front;
        container_front = new_array;
        container_back = container_front + new_size +(new_size/2) - 1;
        first_empty = new_last_value;
    }

    template <typename T>
    void heap_array<T>::reserve(size_type new_total)
    {
        //Check that reserve is bigger than capacity, to avoid unnecessary copies
        if (new_total <= capacity())
            return;
        //if not, create new array in heap, move the current contents, and delete old memory-allocation
        T* new_array{ new T[new_total] };

        T* new_last_value{ new_array };
        for (auto& element : *this)
        {
            *new_last_value = element;
            ++new_last_value;
        }
        delete[] container_front;
        container_front = new_array;
        container_back = container_front + new_total - 1;
        first_empty = new_last_value;

    }

    /*************************/
    /*Member access functions*/
    /*************************/
    
    template <typename T>
    T& heap_array<T>::at(const size_type index)
    {
        if (index >= size())
            throw std::out_of_range("index out of range heap:array<T>.at(index)");
        return *(container_front + index);
    }

    /*******/
    /*Swaps*/
    /*******/
    template <typename T>
    void heap_array<T>::swap(heap_array& other)
    {
        std::swap(container_front, other.container_front);
        std::swap(container_back, other.container_back);
        std::swap(first_empty, other.first_empty);
    }

    template <typename T>
    void swap(heap_array<T>& lhs, heap_array<T>& rhs)
    {
        lhs.swap(rhs);
    }

    /********************/
    /*Equality operators*/
    /********************/

    template <typename T>
    bool operator==(const heap_array<T>& lhs, const heap_array<T>& rhs)
    {
        return std::equal(lhs.cbegin(), lhs.cend(), rhs.cbegin(), rhs.cend());
    }

    template <typename T>
    bool operator!=(const heap_array<T>& lhs, const heap_array<T>& rhs)
    {
        return !(lhs == rhs);
    }

    /******************************/
    /*Overload extraction operator*/
    /******************************/
    
    template <typename T>
    std::ostream& operator<<(std::ostream& out, const heap_array<T>& ha)
    {
        for (const auto& element : ha)
        {
            out << element << ' ';
        }
        out << '\n';
        return out;
    }
    
    /***********/
    /*Push back*/
    /***********/
    template <typename T>
    void heap_array<T>::push_back(const T& value)
    {
        if (first_empty == container_back)
        {
            if (size() != 1)
                reserve(size() + (size() / 2));
            else
                reserve(2);
        }
        ++first_empty;
        *first_empty = value;
    }
}


#endif
