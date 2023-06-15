#include "user.h"
#include "utility_functions.h"

#include <iostream>

void User::add_account()
    {
        clear_screen();
        std::cout << "Adding account, how much for the initial deposit?\n";
        double money{ get_double_input() };
        m_accounts.push_back(Bank_account{ money });
    }

void User::delete_account()
{
    clear_screen();
    for (int i{ 0 }; auto account: m_accounts)
    {
        std::cout << i << ") " << account.get_balance() << "€\n";
    }
    int choice{ get_int_input() };
    std::cout << "Give number for account to erase:\n";

    if (m_accounts.at(choice).get_balance() != 0)
    {
        std::cout << "From/to which account should we even the balance?\n";
        int even{ get_int_input() };
        m_accounts.at(even).deposit_money(m_accounts.at(choice).get_balance());
    }
        m_accounts.erase(m_accounts.begin() + choice);
}
Bank_account& User::choose_account()
{
    for (int i{ 1 }; auto& account : m_accounts)
    {
        std::cout << i << ") Account_ID: "<< account.get_id() << " - " << account.get_balance() << "€\n";
        ++i;
    }
    std::cout << "\nChoose account to open from list:\n";
    int choice{ get_int_input() };
    return m_accounts.at(choice-1);
}
