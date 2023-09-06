#ifndef MEMERROR3_HPP
#define MEMERROR3_HPP

#include <utility>
#include <vector>

/**
 *Problem here with the move. As there was no move constructor defined,
 *there was a double free when using the default constructor. So I created a
 *move constructor and assignment operator. Also delete the copy constructor
 *and assignment.
*/


// Not too rare case, when we have a C library

// Don't worry too much about the code in the extern C block,
// it's basically C code forged so it gets through the compiler
// without errors.
extern "C" {
    #include <string.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <assert.h>

    // Usually C libraries define some structs
    struct some_c_library
    {
        int random;
        char values;
        void* in;
        long a;
        short type;
    };

    // and give you functions to initialise
    inline some_c_library* some_c_new() {
        some_c_library* ptr = (some_c_library*)malloc(sizeof(some_c_library));
        assert(ptr != nullptr);
        // init the values so we don't read uninitialised memory and get
        // confused about that
        ptr->random = 53;
        ptr->values = 2;
        ptr->in = nullptr;
        ptr->a = 0xdeadbeefcafe;
        ptr->type = 0;
        return ptr;
    }

    // and destroy (free resources)
    inline void some_c_free(some_c_library* ptr) {
        free(ptr);
    }

    inline void do_stuff_after_init(some_c_library* ptr) {
        printf("%p:%d%ld%p\n", ptr, ptr->random, ptr->a, ptr->in);
    }
}

// and we want to wrap it into RAII-enabled type.  If you
// use libraries such as FreeType, SDL or GLFW, or many others
// this is a good practice.
class cpp_wrapper
{
    public:
        cpp_wrapper();
        ~cpp_wrapper();

        cpp_wrapper(const cpp_wrapper&) = delete;
        cpp_wrapper& operator=(const cpp_wrapper&) = delete;

        cpp_wrapper(cpp_wrapper&& other) { *this = std::move(other); }
        cpp_wrapper& operator=(cpp_wrapper&& other);

        void do_stuff();
        some_c_library& values() { return *library; }

    private:
        some_c_library* library;
};

cpp_wrapper build_wrapper();

#endif
