#ifndef BANK_USER_GROUP_H
#define BANK_USER_GROUP_H

#include "user.h"
#include "utility_functions.h"

#include <iostream>
#include <string_view>
#include <vector>
namespace Bank
{
    User& choose_user(std::vector<User>& users);
    void add_user(std::vector<User>& users);
    void delete_user(std::vector<User>& users);

    void write_information_to_file(std::vector<User>& users);
}
#endif
