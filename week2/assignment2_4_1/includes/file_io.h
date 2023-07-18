#ifndef FILE_IO_H
#define FILE_IO_H
#include <string>

void print_file_contents(const std::string& file_path, const bool lines, const bool words, const bool characters);
void print_dir_text_size(const std::string& dir_path);

#endif //FILE_IO_H
