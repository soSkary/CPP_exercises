#include "utility_functions.h"
#include "bank_account.h"
#include "user.h"
#include "bank_user_group.h"

#include <iostream>
#include <iomanip>
#include <vector>

//function for looping inside account, the third and deepest interface
void account_loop(Bank_account& account)
{
    while (true)
    {
        clear_screen();
        std::cout << "ACCOUNT_ID: " << account.get_id() << "\n\n";
        std::cout
            << "1) Display balance\n"
            << "2) Withdraw money\n"
            << "3) Deposit money\n"
            << "4) Quit\n";
        std::cout << "\nChoose option by giving number (1 - 4):\n";
        int choice{ get_int_input() };
        switch (choice)
        {
        case 1:
            account.display_balance();
            break;
        case 2:
            account.withdraw_money();
            break;
        case 3:
            account.deposit_money();
            break;
        case 4:
            return;
        default:
            continue;
        }
    }
}

//function for the main user loop, the second interface
void user_loop(User& user)
{
    while (true)
    {
        clear_screen();
        std::cout << "Banking application of " << user.get_name() << ' '
            << user.get_phone() << ' ' << user.get_adress() << "\n\n"
            << "CUSTOMER_ID: " << user.get_id() << "\n\n";        
        std::cout
            << "1) Choose account\n"
            << "2) Add account\n"
            << "3) Delete account\n"
            << "4) Quit\n";
        std::cout << "\nChoose option by giving number (1 - 4):\n";
            
        int choice{ get_int_input() };
        switch (choice)
        {
        case 1:
            if (user.m_accounts.empty())
            {
                std::cout << "\nNO ACTIVE ACCOUNTS, ADD ONE FIRST!\n\n";
            }
            else
            {
                account_loop(user.choose_account());
            }
            continue;
        case 2:
            user.add_account();
            continue;
        case 3:
            user.delete_account();
            continue;
        case 4:
            std::cout << "Exiting banking application.\n\n";
            return;
        default:
            continue;
        }
    }
}

//Function for managing users, the first interface
void bank_loop(std::vector<User>& users)
{

    while (true)
    {
        clear_screen();
        std::cout << "Oskar's Bank (OB Oy) (Not so)Internet banking application\n\n";        
        std::cout
            << "1) Choose user\n"
            << "2) Add user\n"
            << "3) Delete user\n"
            << "4) Quit\n";
        std::cout << "\nChoose option by giving number (1 - 4):\n";
            
        int choice{ get_int_input() };
        switch (choice)
        {
        case 1:
            if (users.empty())
            {
                std::cout << "\nNO ACTIVE USERS, ADD ONE FIRST!\n\n";
            }
            else
            {
                user_loop( Bank::choose_user(users));
            }
            continue;
        case 2:
            Bank::add_user(users);
            continue;
        case 3:
            Bank::delete_user(users);
            continue;
        case 4:
            std::cout << "Saving to log and exiting banking application.\n\n";
            Bank::write_information_to_file(users);
            return;
        default:
            continue;
        }

    }
}

int main()
{
    //set cout to print only two decimal places
    std::cout << std::fixed << std::setprecision(2);

    std::vector<User> users{};
    users.push_back(User {"Milja Miljonääri", "Rahakatu 1, 99999, Fyrkka", "+35844444444"});
    users.push_back(User {"Testi Tyyppi", "Testitie 13, 73571, Testi", "+3587357173571"});
    
    bank_loop(users);
    
    

    return 0;
}
