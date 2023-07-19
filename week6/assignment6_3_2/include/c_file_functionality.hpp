#ifndef C_FILE_FUNCTIONALITY_HPP
#define C_FILE_FUNCTIONALITY_HPP

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <string>


class c_file_functionality
{
public:

    c_file_functionality(const std::string& open_file_named);
    ~c_file_functionality();

    std::string read_line();
    uint32_t file_size();

private:
    FILE* file_handle;
    std::string file_name;
};


#endif
