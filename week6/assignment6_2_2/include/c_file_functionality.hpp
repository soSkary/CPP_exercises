#ifndef C_FILE_FUNCTIONALITY_HPP
#define C_FILE_FUNCTIONALITY_HPP

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <string>


class c_file_functionality
{
public:

    c_file_functionality(const std::string& user_file_name);
    ~c_file_functionality();

    std::string read_next_line_of_file();
    uint32_t check_file_size();

private:
    FILE* file_handle;
    std::string file_name;
};


#endif
