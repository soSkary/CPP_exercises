#ifndef BANK_USER_H
#define BANK_USER_H

#include "bank_account.h"

#include <string>
#include <string_view>
#include <vector>

struct User
{
    std::string m_name{};
    std::string m_adress{};
    std::string m_phone{};
    std::vector<Bank_account> m_accounts{};
    unsigned int m_user_id{};

    bool online{};

    User(std::string_view name, std::string_view adress, std::string_view phone)
        : m_name{ name }, m_adress{ adress }, m_phone{ phone }
    {
        static unsigned int user_id{ 0 };
        m_user_id = user_id++;
    }
    std::string_view get_name() { return m_name; };
    std::string_view get_phone() { return m_phone; };
    std::string_view get_adress() { return m_adress; };
    unsigned int get_id() { return m_user_id; };

    void add_account();
    void delete_account();
    Bank_account& choose_account();
};

#endif
