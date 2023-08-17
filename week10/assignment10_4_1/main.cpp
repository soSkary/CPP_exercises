#define BACKWARD_HAS_DW 1

#include <fmt/core.h>
#include <fmt/color.h>

#include <nlohmann/json.hpp>

#include <cassert>
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using json = nlohmann::json;

int main()
{

    //Exercise 1
    int meaning_of_life{ 42 };

    fmt::print( "The meaning of life is {}\n", meaning_of_life );
    fmt::print(fg(fmt::color::green) | bg(fmt::color::red), "This is quite cool, and has some neat features too!\n");
    fmt::print("just checking if the colors are persistent\n");

    //Exercise 2
    //The Backward Stack Tracing can be toggled with CMake build flag -DBACKWARD_ON=OFF or ON
//    assert(0);


    //Exercise 3
    std::ifstream json_file("monsters.json");
    json data{ json::parse(json_file) };

    //fmt::print("{}\n", data);
    std::cout << data << '\n';


    std::unordered_map<std::string, std::string> to_json;
    to_json.emplace("name", "Joseph");
    to_json.emplace("age", "22");
    to_json.emplace("profession", "cook");

    json person(to_json);

    std::ofstream save_file("person.json");
    save_file << std::setw(4) << person << '\n';



    return 0;
}
