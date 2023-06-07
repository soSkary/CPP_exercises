#include <iostream>

namespace User_defined
{
    int value{ 10 };
}

void print_function()
{
    int value{ 1000 };
    std::cout << "print_function() value: " << value << " has local scope!\n";
    std::cout << "This means we can only access it inside the function itself.\n\n";
}

int main()
{
    print_function();
    std::cout << "To get access to the namespaced variable, we use\n"
        << "Namespace::variable_name, like this:\nUser_defined::value "
        << User_defined::value << "\n\n";

    std::cout << "This ensures there's only a minimal chance for naming errors!\n";
    std::cout << "... if you use appropriate namespaces, eg. 'namespace std{}' isn't a good idea! ;)\n";

    return 0;

}
