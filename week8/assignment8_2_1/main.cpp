#include <cstdint>
#include <iostream>
#include <string>
#include <type_traits>

//Exercise 1

template <typename T>
void type_of_value(T&& value)
{
    if (std::is_rvalue_reference_v<T&&>)
    {
        std::cout << value << " is a rvalue reference\n";
    }
    else
        std::cout << value << " is a lvalue reference\n";

}




//Exercise 2
template <bool console_output>
class my_class
{
public:
    //default constructor
    my_class()
    {
        if (console_output)
            std::cout << "instance of my_class created\n";
        ++calls_to_instance;
    }
    //copy
    my_class(const my_class& other)
    {
        if (console_output)
            std::cout << "instance of my_class copied from " << other.name << '\n';
        value = other.value;
        calls_to_instance = 1;
    }
    //move
    my_class(my_class&& other)
    {
        if (console_output)
            std::cout << "instance of my_class moved from " << other.name << '\n';
        value = other.value;
        calls_to_instance = ++other.calls_to_instance;

        other.value = 0;
        other.calls_to_instance = 0;
    }

    //destructor
    ~my_class()
    {
        if (console_output)
            std::cout << "~Instance of my_class destroyed: " << name << " value: "<< value << " calls to instance: " << calls_to_instance
            << '\n';
    }

    int32_t value;
    std::string name;
private:
    uint16_t calls_to_instance{ 0 };
};

class my_class2
{
public:
    my_class2() { ++instances; }
    my_class2(std::string new_data) : data{ new_data } { ++instances; }

    my_class2(const my_class2&) = delete;
    
    my_class2(my_class2&& other) : data{ std::move(other.data) }
    {
        other.data = "";
        other.has_been_moved = true;
    }

    ~my_class2()
    {
        if (!has_been_moved)
        {
            std::cout << data << " destroyed. There was " << instances << " instances.";
            --instances;
            std::cout << " Now there's " << instances << " left.\n";
        }
    }
    
    friend std::ostream& operator<<(std::ostream& out, const my_class2& mc2);

private:
    std::string data{""};
    bool has_been_moved{ false };
    
    static inline uint16_t instances{ 0 };

};

std::ostream& operator<<(std::ostream& out, const my_class2& mc2)
{
    out << mc2.data;
    return out;
}



int main()
{
    std::cout << "EXERCISE 1\n\n";
    int a{ 1 };

    int& b{ a };
    
    type_of_value(a);
    type_of_value(b);
    type_of_value(3);

    std::cout << "\nEXERCISE 2\n\n";
    {
        
        my_class<true> m_c1;
        m_c1.value = 2;
        m_c1.name = "m_c1";

        my_class<false> m_cf;
        m_cf.value = 0;
        m_cf.name = "m_cf";
        auto mc_copy{ m_c1 };
        mc_copy.name = "mc_copy";
        auto mc_move{ std::move(m_c1) };
        mc_move.name = "mc_move";
        
    }
    
    {

        std::cout << "\nEXERCISE 3\n\n";

        my_class2 mc2_a{ "tonttu" };
        my_class2 mc2_b{ "joulupukki" };
        my_class2 mc2_c{ "joulumuori" };
        my_class2 mc2_d{ "petteri" };

        std::cout << "mc2_a: " << mc2_a << '\n';
        std::cout << "mc2_b: " << mc2_b << '\n';
        std::cout << "mc2_c: " << mc2_c << '\n';
        std::cout << "mc2_d: " << mc2_d << '\n';

        my_class2 mc2_e{ std::move(mc2_a) };
        my_class2 mc2_f{ std::move(mc2_b) };

        std::cout << "Move a to e, and b to f:\n";

        std::cout << "mc2_a: " << mc2_a << '\n';
        std::cout << "mc2_e: " << mc2_e << '\n';
        std::cout << "mc2_b: " << mc2_b << '\n';
        std::cout << "mc2_f: " << mc2_f << '\n';
    
    }



    return 0;
}
