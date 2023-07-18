#ifndef C_FILE_FUNCTIONALITY_HPP
#define C_FILE_FUNCTIONALITY_HPP

#include <cstdio>
#include <cstdlib>
#include <string>


class c_file_functionality
{
public:
    FILE* file_handle;

    c_file_functionality(const std::string& file_name);
    ~c_file_functionality();
    
private:
};


#endif
