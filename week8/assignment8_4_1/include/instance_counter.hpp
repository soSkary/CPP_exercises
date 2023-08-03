#ifndef INSTANCE_COUNTER_HPP
#define INSTANCE_COUNTER_HPP

#include <iostream>

class instance_counter
{
public:
    instance_counter() { ++instances; }
    instance_counter(bool print) : enable_print{print} { ++instances; }
    instance_counter(std::string new_data) : data{ new_data } { ++instances; }
    instance_counter(const char* new_data) : data{ new_data } { ++instances; }
    instance_counter(std::string new_data, bool print) : data{ new_data }, enable_print{print} { ++instances; }
    instance_counter(const char* new_data, bool print) : data{ new_data }, enable_print{print} { ++instances; }

    instance_counter(const instance_counter&) = delete;

    instance_counter(instance_counter&& other) : data{ std::move(other.data) }
    {
        if (other.has_been_moved)
        {
            has_been_moved = true;
            return;
        }

        other.data = "";
        other.has_been_moved = true;
    }

    ~instance_counter()
    {
        if (!has_been_moved)
        {
            if (enable_print)
            {
                std::cout << data << " destroyed. There was " << instances << " instances.";
                --instances;
                std::cout << " Now there's " << instances << " left.\n";
            }
            else
                --instances;
        }
    }

    static inline uint16_t instances{ 0 };

    std::string data{""};
    bool enable_print{ false };
    
    friend std::ostream& operator<<(std::ostream& out, const instance_counter& i_counter);

private:
    bool has_been_moved{ false };


};

std::ostream& operator<<(std::ostream& out, const instance_counter& i_counter)
{
    out << i_counter.data;
    return out;
}


#endif
