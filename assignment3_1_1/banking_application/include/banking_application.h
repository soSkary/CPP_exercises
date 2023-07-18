#ifndef BANKING_APPLICATION_H
#define BANKING_APPLICATION_H

#include "bank_account.h"
#include "user.h"
#include "bank_user_group.h"

void banking_application();
void bank_loop(std::vector<User>& users);
void user_loop(User& user);
void account_loop(Bank_account& account);
#endif
