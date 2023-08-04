#include "memerror1.hpp"

 //large_object(const large_object&) = default; // default the copy constructor, since
                                                     // the class is basically just the handle
                                                     // anyway
/**
 *The defaulted copy constructor was the culprit,
 *as the handle was identical for the two,
 *they tried to erase twice from the same handle in the destructor
**/


// Implementations
large_object::large_object() {
    int next_handle = object_storage.size();
    
    // create new default-initialised value in the container
    // and set our handle to match the index
    object_storage.push_back({std::string("object number ") + std::to_string(next_handle) });
    handle = next_handle;
}

large_object::~large_object() {
    // delete the handle'th element from the storage
    if (handle >= 0)
    {
        object_storage.erase(object_storage.begin() + handle);
    }
}

large_object::large_object(const large_object& other) {
    handle = object_storage.size();
    object_storage.push_back({ std::string("object number ") + std::to_string(other.handle) });
}

large_object& large_object::operator=(const large_object& other) {
    handle = object_storage.size();
    object_storage.push_back({ std::string("object number ") + std::to_string(other.handle) });
}

// int main() {
//     // segmentation fault
//     large_object a;
//     large_object b = a;
//     large_object c;
// }
