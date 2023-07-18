#include "c_file_functionality.hpp"
#include <iostream>

int main()
{
    c_file_functionality opened_file("text.txt");

    std::cout << "File size: " << opened_file.check_file_size() << " bytes\n";
    opened_file.read_next_line_of_file();
    
    std::cout << "File size: " << opened_file.check_file_size() << " bytes\n";
    opened_file.read_next_line_of_file();
    opened_file.read_next_line_of_file();
    std::cout << "File size: " << opened_file.check_file_size() << " bytes\n";

    
    return 0;

}
