#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "math_utils.h"
#include "string_utils.h"

#include "bank.h"

#include <stdexcept>

TEST_CASE("Testing math_utils.cpp")
{
    CHECK(add(1, 2) == 3);
    CHECK(add(252, -752) == -500);
    CHECK(subtract(10, 2) == 8);
    CHECK(subtract(-10, 2) == -12);
    CHECK(multiply(3, 4) == 12);
    CHECK(multiply(370, 0) == 0);
    CHECK(multiply(-7, 8) == -56);
    CHECK(multiply(-7, -8) == 56);
    CHECK(divide(15, 3) == 5);
    CHECK(divide(-15, 3) == -5);
    CHECK_THROWS_AS(divide(1, 0), std::exception);
};

TEST_CASE("Testing string_utils.cpp")
{
    CHECK(reverse_string("This should be") == "eb dluohs sihT");
    CHECK(reverse_string("123, ABC, 321") == "123 ,CBA ,321");
    CHECK(to_lower_case("THISSHOULDBE") == "thisshouldbe");
    CHECK(to_lower_case("Checking f0r SP4ces! and IRREgul&rities")
        == "checking f0r sp4ces! and irregul&rities");
    CHECK(is_palindrome("Fish") == false);
    CHECK(is_palindrome("ABBA") == true);
    CHECK(is_palindrome("KaYAk") == true);
};


TEST_CASE("Testing banking_application")
{
    //Check bank-account withdraw, deposit, and display_balance functions
    Bank_account bank_account{ 1000.0 };

    CHECK(bank_account.display_balance() == 1000.0);
    bank_account.withdraw_money(150.0);
    CHECK(bank_account.display_balance() == 850.0);
    bank_account.deposit_money(1000.0);
    CHECK(bank_account.display_balance() == 1850.0);
    CHECK(bank_account.withdraw_money(2000.0) == 0.0);

    std::vector<User> users;
    users.push_back(User{ "Matti1", "Tie1", "04001" });
    users.push_back(User{ "Matti2", "Tie2", "04002" });
    users.push_back(User{ "Matti3", "Tie3", "04003" });

    CHECK(users.at(2).get_id() == 2);
    CHECK(users.at(2).get_name() == "Matti3");
    CHECK(users.at(2).get_phone() == "04003");
    CHECK(users.at(2).get_adress() == "Tie3");
    
};

