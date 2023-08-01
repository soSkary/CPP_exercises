#ifndef UTILITY_FUNCTIONS_H
#define UTILITY_FUNCTIONS_H
#include <string>

//strings to file paths
namespace Path
{
const std::string folder{"./account_files"};
const std::string file{"./account_files/account_log"};
}

int get_int_input();
double get_double_input();
char get_char_input();
std::string get_string_input();
void clear_screen();

#endif
