#include "caesar_cipher.h"
#include "math_operations.h"
#include <cxxopts.hpp>

#include <cassert>
#include <iostream>

int main(int argc, char* argv[])
{
    //Create an instance of options
    cxxopts::Options options("assignment2_2_2", "Program to do do addition, subtraction, multiplication and division of two values on the command line or en-/decryption of message");

    //flags for -a, -s, -m, -d, -e, -u and two double value fields
    options.add_options()
        ("a,add", "Do addition", cxxopts::value<bool>()->default_value("false"))
        ("s,subtract", "Do subtraction", cxxopts::value<bool>()->default_value("false"))
        ("m,multiply", "Do multiplication", cxxopts::value<bool>()->default_value("false"))
        ("d,divide", "Do division", cxxopts::value<bool>()->default_value("false"))
        ("e,encrypt", "Encrypt message",cxxopts::value<bool>()->default_value("false"))
        ("u,decrypt", "Decrypt message", cxxopts::value<bool>()->default_value("false"))
        ("value1", "The first value to be operated on", cxxopts::value<double>()->default_value("0.0"))
        ("value2", "The second value to be operated on", cxxopts::value<double>()->default_value("0.0"))
        ;
    //first parse the value fields as positional
    options.parse_positional({ "value1", "value2" });
    //then parse the rest
    auto result = options.parse(argc, argv);

    //check if either of message en-/decryption flags raised
    if (result["encrypt"].as<bool>())
    {
        caesar_encrypt();
    }
    else if (result["decrypt"].as<bool>())
    {
        std::cout << caesar_decrypt() << '\n';
    }
    //if not, check for math operations flags
    else
    {
        //This is just to give a cleaner look, could be done to all cxxopts variables though :)
        const double& value1{ result["value1"].as<double>() };
        const double& value2{ result["value2"].as<double>() };
        
        double return_value;
        
        if (result["add"].as<bool>() && result.count("value1") && result.count("value2"))
        {
            return_value = add(value1, value2);
        }
        else if (result["subtract"].as<bool>() && result.count("value1") && result.count("value2"))
        {
            return_value = subtract(value1, value2);
        }
        else if (result["multiply"].as<bool>() && result.count("value1") && result.count("value2"))
        {
            return_value = multiply(value1, value2);
        }
        else if (result["divide"].as<bool>() && result.count("value1") && result.count("value2"))
        {
            assert(value2 != 0.0 && "Can't divide by zero, exiting.\n");
            return_value = divide(value1, value2);
        }

        //if flags or values missing, get operations manually
        else
        {
            std::cout << "Didn't get flags or values, enter operation manually:\n";
            return_value = get_operation_and_values();
        }
        std::cout << return_value << '\n';
    }

    return 0;
}
