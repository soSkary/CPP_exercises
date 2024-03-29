#include "file_io.h"
#include <cxxopts.hpp>

#include <iostream>

int main(int argc, char* argv[])
{
    //Use submodule cxxoptions
    cxxopts::Options options("assignment2_1_4", "Program for reading input files");

    //Add flags (=options) to look for on the command line
    options.add_options()
        //Set default_value to false, ie. if flag not present
        ("l,lines", "Enable line counter", cxxopts::value<bool>()->default_value("false"))
        ("w,words", "Enable word counter", cxxopts::value<bool>()->default_value("false"))
        ("c,chars", "Enable character counter", cxxopts::value<bool>()->default_value("false"))
        ("d,dirsize", "Return size of .txt files in directory", cxxopts::value<bool>()->default_value("false"))
        ("file_path", "Give file path to text to be parsed", cxxopts::value<std::string>());
    //Parse the flag itself, not the parameter after the flag
    options.parse_positional({ "file_path" });
    //Parse rest of the flags
    auto result = options.parse(argc, argv);

    //Check that a file_path is present
    if (result.count("file_path") == 0)
    {
        std::cout << "Please give file path as command-line argument.\n";
    }
    //If dirsize flag present, run function to count size of .txt files in folder 
    else if (result["dirsize"].as<bool>())
    {
        print_dir_text_size(result["file_path"].as<std::string>());
    }
    //If file path present, run function.
    //Pass filepath and flags lines, words, and chars as booleans
    else
    {
        print_file_contents(result["file_path"].as<std::string>(), result["lines"].as<bool>(), result["words"].as<bool>(), result["chars"].as<bool>());
    }

    return 0;
}
