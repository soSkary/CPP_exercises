#include <iostream>

struct User_structure
{
private:
    int m_value{0};

public:
    int get_value()
    {
        return m_value;
    }
    void set_value(const int value)
    {
        m_value = value;
    }
};

int main()
{
    User_structure user_struct{};

    // private user_struct.m_value is created with the struct object and initialized with 0;

    std::cout << "user_struct.get_value() after initialization: " << user_struct.get_value() << '\n';

    //set m_value with public member function set_value(int);
    user_struct.set_value(67);

    std::cout << "user_struct.get_value() after setting value: " << user_struct.get_value() << '\n';

    return 0;
    //private user_struct.m_value dies as the struct goes out of scope
}
