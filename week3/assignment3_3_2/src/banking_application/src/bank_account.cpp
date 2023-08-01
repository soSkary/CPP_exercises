#include "bank_account.h"
#include "utility_functions.h"

#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>

//member function for depositing money
void Bank_account::deposit_money()
{
    clear_screen();
    std::cout << "Please define amount to add to account:\n";
    m_money += get_double_input();

    std::cout << "The new balance of your account is:\n";
    display_balance();
}

void Bank_account::deposit_money(const double money)
{
    m_money += money;
}
//member function for withdrawing money
double Bank_account::withdraw_money()
{
    clear_screen();
    display_balance();
    std::cout << "Please define amount to withdraw from account:\n";
    double withdrawal{ get_double_input() };
    if (m_money >= withdrawal)
        m_money -= withdrawal;
    else
    {
        std::cout << "Insufficient funds.\n";
        return 0;
    }
    std::cout << '\n';
    display_balance();
    std::cout << "\n\n";
    return withdrawal;
}

double Bank_account::withdraw_money(const double withdrawal)
{
    if (m_money >= withdrawal)
        m_money -= withdrawal;
    else
    {
        std::cout << "Insufficient funds.\n";
        return 0.0;
    }
    return withdrawal;
}

//member function for displaying current balance
double Bank_account::display_balance()
{
    std::cout << "\n\nThe balance of your account is:\n" << m_money << " €\n\n";
    return m_money;
}
