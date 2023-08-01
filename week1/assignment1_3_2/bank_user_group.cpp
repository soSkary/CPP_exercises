#include "bank_user_group.h"
#include "utility_functions.h"

#include <filesystem>
#include <fstream>

//Function for choosing and returning a user
User& Bank::choose_user(std::vector<User>& users)
    {
        clear_screen();
        for (int i{ 1 }; auto& user : users)
        {
            std::cout << i << ") " << user.get_name() << " User_ID: " << user.get_id() << '\n';
            ++i;
        }
        std::cout << "\nChoose user from list:\n";
        int choice{ get_int_input() };
        return users.at(choice-1);
    }
//Function for adding a user to the banking program!
void Bank::add_user(std::vector<User>& users)
{
    clear_screen();
    std::cout << "Please give name for user to be added:\n";
    std::string name{get_string_input()};
    std::cout << "Please give adress for user to be added:\n";
    std::string adress{get_string_input()};
    std::cout << "Please give phone number for user to be added:\n";
    std::string phone{get_string_input()};

    users.push_back( User{ name, adress, phone});
    std::cout << "\n\nUser " << name << ", " << adress << ", " << phone << " added!\n\n";  
}
//Function for deleting a user
void Bank::delete_user(std::vector<User>& users)
{
    clear_screen();
    for (int i{ 0 }; auto& user: users)
    {
        std::cout << i << ") " << user.get_name() << ", Customer_ID " << user.get_id() << "\n";
        ++i;
    }
    int choice{ get_int_input() };
    std::cout << "Give number for user to delete:\n";

    std::cout << "Are you sure? (y/n)\n";
    if (get_char_input() == 'y')
    {
        std::cout << "Deleting user " << users.at(choice).get_name() << '\n';
        users.erase(users.begin() + choice-1);
        return;
    }
    else
    {
        std::cout << "Canceling deletion, returning to user menu.\n\n";
    }

}

//Function for logging into file
void Bank::write_information_to_file(std::vector<User>& users)
{
    /*
    Could implement session id later
    */
    namespace fs = std::filesystem;
    //Path to folder /account_files inside project folder
    fs::path path{Path::folder};
    //if it doesn't exist, create it
    if (!fs::exists(path))
    {
        fs::create_directory(path);
    }
    //Set path name to specified path (defined in utility_functions.h)
    path = (Path::file);
    //Open a outputstream that writes to the end of file
    std::ofstream account_file(path, std::iostream::app);
    account_file << "USER,USER_ID,ACCOUNT_ID,BALANCE\n";
    //Loop through every user..
    for (auto& user: users)
    {
        //and every account, of every user, and write their data to separate lines
        for (auto& account: user.m_accounts)
        {
            account_file << user.get_name() << ',' << user.get_id() 
            << ',' << account.get_id() << ',' << account.get_balance() <<"€\n";
        }

    }
    //Write and close the file
    account_file.close();   
}
