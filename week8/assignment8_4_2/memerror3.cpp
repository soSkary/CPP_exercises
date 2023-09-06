#include "memerror3.hpp"


cpp_wrapper::cpp_wrapper() {
    library = some_c_new();
}

cpp_wrapper::~cpp_wrapper() {
    if (library)
        some_c_free(library);
}

cpp_wrapper& cpp_wrapper::operator=(cpp_wrapper&& other) {
    library = std::exchange(other.library, nullptr);
    return *this;
}

void cpp_wrapper::do_stuff() {
    do_stuff_after_init(library);
}

// Common thing, create a thing, set it to certain non-default initial values.
cpp_wrapper build_wrapper() {
    cpp_wrapper rval;
    rval.values().random = 42;

    // move to avoid copy (if compiler doesn't handle guaranteed copy elision)
    return std::move(rval);
}

// int main() {
//     // we could use the C library like this, but it's usually a bad idea
//     // (bug-prone), so we want to do the wrapping to handle some of the
//     // busywork for us. (And have RAII so we don't forget to clean up
//     // after ourselves)
//     some_c_library* lib = some_c_new();
//     do_stuff_after_init(lib);
//     some_c_free(lib);

//     // with C++ we would use it like (so we trade initial wrapping work to
//     // ease of use later on)
//     cpp_wrapper wrapped;
//     wrapped.do_stuff();

//     // But our wrapper might still be a bit under construction...
//     auto wrapped2 = build_wrapper();

//     wrapped2.do_stuff();
// }
