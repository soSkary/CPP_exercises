#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <string_view>
#include <vector>

//constant to define how many lines to print to "clear screen"
const int clear_screen_newlines{ 25 };
//function for getting user input INT
int get_user_int()
{
    int value;
    while (true)
    {
        std::cout << "Input integer value: ";
        std::cin >> value;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
            return value;

    }
}
//function for getting user input DOUBLE
double get_user_double()
{
    double value;
    while (true)
    {
        std::cout << "Input value: ";
        std::cin >> value;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
            return value;

    }
}
//function for getting user input CHAR
char get_user_char()
{
    char value;
    while (true)
    {
        std::cout << "Input character: ";
        std::cin >> value;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
            return value;
    }
}
//function for clearing or refreshing screen
void clear_screen()
{
    for (int i{ 0 }; i < clear_screen_newlines; ++i)
    {
        std::cout << '\n';
    }
}


struct Bank_account
{
private:
    // std::string m_name{};
    // std::string m_adress{};
    // std::string m_phone{};

    unsigned int m_account_id{};
    double m_money{};
    

public:
    Bank_account(const double money = 0.0)
        :  m_money{money}
    {
        static unsigned int account_id{ 0 };
        m_account_id = account_id++;
    }

    
    unsigned int get_id() { return m_account_id; };
    const double get_balance() { return m_money; };
    void deposit_money();
    void deposit_money(const double money);
    int withdraw_money();
    void display_balance();
    
        
};

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

//member function for depositing money
void Bank_account::deposit_money()
{
    clear_screen();
    std::cout << "Please define amount to add to account:\n";
    m_money += get_user_double();

    std::cout << "The new balance of your account is:\n";
    display_balance();
}

void Bank_account::deposit_money(const double money)
{
    m_money += money;
}
//member function for withdrawing money
int Bank_account::withdraw_money()
{
    clear_screen();
    display_balance();
    std::cout << "Please define amount to withdraw from account:\n";
    double withdrawal{ get_user_double() };
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
//member function for displaying current balance
void Bank_account::display_balance()
{
    std::cout << "The balance of your account is:\n" << m_money << " €\n\n";
    return;
}
void User::add_account()
    {
        clear_screen();
        std::cout << "Adding account, how much for the initial deposit?\n";
        double money{ get_user_double() };
        m_accounts.push_back(Bank_account{ money });
    }

    void User::delete_account()
    {
        clear_screen();
        for (int i{ 0 }; auto account: m_accounts)
        {
            std::cout << i << ") " << account.get_balance() << "€\n";
        }
        int choice{ get_user_int() };
        std::cout << "Give number for account to erase:\n";

        if (m_accounts.at(choice).get_balance() != 0)
        {
            std::cout << "From/to which account should we even the balance?\n";
            int even{ get_user_int() };
            m_accounts.at(even).deposit_money(m_accounts.at(choice).get_balance());
        }
            m_accounts.erase(m_accounts.begin() + choice);
    }
    Bank_account& User::choose_account()
    {
        for (int i{ 1 }; auto& account : m_accounts)
        {
            std::cout << i << ") " << account.get_balance() << "€\n";
            ++i;
        }
        std::cout << "Choose account to open from list:\n";
        int choice{ get_user_int() };
        return m_accounts.at(choice-1);
    }

//function for looping inside account
void account_loop(Bank_account& account)
{
    while (true)
    {
        std::cout << "ACCOUNT_ID: " << account.get_id() << "\n\n";
        std::cout
            << "1) Display balance\n"
            << "2) Withdraw money\n"
            << "3) Deposit money\n"
            << "4) Quit\n";
        std::cout << "\nChoose option by giving number (1 - 4):\n";
        int choice{ get_user_int() };
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
//function for the main banking loop, or the user interface
void user_loop(User& user)
{
    
    while (true)
    {
        std::cout << "Bank account of " << user.get_name() << ' '
            << user.get_phone() << ' ' << user.get_adress() << "\n\n"
            << "CUSTOMER_ID: " << user.get_id() << "\n\n";        
        std::cout
            << "1) Choose account\n"
            << "2) Add account\n"
            << "3) Delete account\n"
            << "4) Quit\n";
        std::cout << "\nChoose option by giving number (1 - 4):\n";
            
        int choice{ get_user_int() };
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

int main()
{
    //set cout to print only two decimal places
    std::cout << std::fixed << std::setprecision(2);

    User user("Milja Miljonääri", "Rahakatu 1, 99999, Fyrkka", "+35844444444");

    User user2("Testing ID", "Somewhere Over The Rainbow", "666-666-6666");
    //Bank_account user("Milja Miljonääri", "Rahakatu 1, 99999, Fyrkka", "+35844444444", 15'000'000.00);
    user_loop(user);
    //Bank_account user2("Testing ID", "Somewhere Over The Rainbow", "666-666-6666", 0.50);
    user_loop(user2);

    return 0;
}
