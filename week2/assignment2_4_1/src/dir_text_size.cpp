#include "file_io.h"

#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

void print_dir_text_size(const std::string& dir_path)
{
    fs::path check_path{dir_path};

    //Check if path is not a directory
    if (!fs::is_directory(check_path))
    {
        std::cout << "Invalid path: " << dir_path << '\n';
    }
    else
    {
        
        std::uintmax_t text_files_size{ 0 };
        //Loop through the files in directory
        for (auto const& file : fs::directory_iterator(check_path))
        {
            //If file is a .txt file, add its size to the text_files_size
            if (file.path().extension() == ".txt")
            {
                text_files_size += fs::file_size(file);
            }
        }
        std::cout << "The txt files in " << dir_path << " are a combined size of "
            << text_files_size << " bytes, or " << text_files_size/1024 << "kB\n";
    }
}
