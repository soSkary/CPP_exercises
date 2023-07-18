#include "c_file_functionality.hpp"

c_file_functionality::c_file_functionality(const std::string& file_name)
{
    file_handle = std::fopen(file_name.c_str(), "r");
}

c_file_functionality::~c_file_functionality()
{
    
}
