#include "caesar_cipher.h"

#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>

namespace fs = std::filesystem;

int get_user_int()
{
    while (true)
    {
        int value;
        std::cin >> value;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        return value;
    }
}

std::string get_user_string()
{
    std::string value;
    std::getline(std::cin >> std::ws, value);
    return value;
}

//Check for ascii values between 32 and 126 ie. printable values
bool char_is_print(char ch)
{
    return std::isprint(static_cast<unsigned char>(ch));
}

void write_message_to_file(const std::string& message)
{
    //Create a filesystem path to where to store the message
    fs::path message_path("message/message.txt");
    
    //Check if directory doesn't exist, and if not, create it
    if (!fs::exists(message_path.parent_path()))
    {
        fs::create_directory(message_path.parent_path());
    }
    
    //Open a file for writing, erase if one exists
    std::ofstream file_output(message_path, std::ios::trunc);

    //Write the message to file in a for loop
    for (const auto& elem : message)
    {
        file_output << elem;
    }
    //file_output << '\n';
    
    //Close the file and exit function
    file_output.close();
}

std::string read_message_from_file()
{
    //Create a filesystem path to where the message is stored
    fs::path message_path("message/message.txt");

    //Open the file
    std::ifstream file_input(message_path);

    //Check that open was succesful
    if (!file_input)
    {
        return std::string {"ERROR - couldn't open file!"};
    }

    //Create a string and read the message to it line by line
    std::string message;
    while (std::getline(file_input, message))
    {
    }

    //Close the file and return the message
    file_input.close();

    return message;

}
//Function for encrypting a message using caesar chiffer
void caesar_encrypt()
{
    std::cout << "Please give message to encrypt: ";
    std::string message{get_user_string()};

    std::cout << "Please give encryption key to use: ";
    int encryption_key{ get_user_int() };

    //temporary integer for bounds checking
    int temp;
    //Encryption done by adding to ascii value of character
    for (auto it{ message.begin() }; it != message.end(); ++it)
    {
        if (char_is_print(*it))
        {
            temp = *it + encryption_key;
            //if value goes out of bounds, round values back to isprint (account for both negative and positive keys)
            if (temp < 32)
            {
                temp += 95;
            }
            else if (temp > 126)
            {
                temp -= 95;
            }
            *it = temp;
        }
    }
    //Message is written encrypted to file
    write_message_to_file(message);
}

//Function for decrypting a message
std::string caesar_decrypt()
{
    //Load the encrypted message from file
    std::string message{read_message_from_file()};

    //Decrypted with key
    std::cout << "Please enter decryption_key: ";
    int decryption_key{ get_user_int() };

    int temp;
    //Decryption done by subtracting from ascii value of character
    for (auto it{ message.begin() }; it != message.end(); ++it)
    {
        if (char_is_print(*it))
        {
            temp = *it - decryption_key;
            //if value goes out of bounds, round values back to isprint (account for both negative and positive keys)
            if (temp < 32)
            {
                temp += 95;
            }
            else if (temp > 126)
            {
                temp -= 95;
            }
            *it = temp;
        }
    }
    return message;
}
