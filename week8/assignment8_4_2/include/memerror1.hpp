#ifndef MEMERROR1_HPP
#define MEMERROR1_HPP

#include <vector>
#include <utility>
#include <iostream>
#include <string>

//
// A common pattern is to store elements contiguous in memory, and then just store a
// handle to the stored element with the class actually used.
//
// This way objects of similar type can be stored contiguously, and we can avoid some
// cache trashing.
//

// We have a class for the actual data we store, usually not directly accessible
struct object_data
{
    std::string name;
};

// and the storage in a vector.  This usually is a bit less obvious than a static
// global variable, but it'll do here.


// And then the publicly available class we actually use to access the data
class large_object
{
    public:
        large_object();
        ~large_object();

        large_object(const large_object& other);
        large_object& operator=(const large_object& other);

            //large_object(const large_object&) = delete; // default the copy constructor, since
                                                     // the class is basically just the handle
                                                     // anyway
inline static std::vector<object_data> object_storage;

private:
    // int is often used as a handle, so negative values an be used to denote
        // errors.  std::ssize_t is another often seen choice, but we aren't going
        // to create more than INT_MAX elements in our container here.
        int handle;
};

#endif
