#include "exercise1.hpp"
#include "exercise2.hpp"

#include <iostream>

int main()
{

    status current_status(random_status_code());

    switch (current_status)
    {
    case status::success:
        std::cout << "Status: success\n";
        break;
    case status::loading_error:
        std::cout << "Status: loading error\n";
        break;
    case status::saving_error:
        std::cout << "Status: saving error\n";
        break;
    default:
        std::cout << "Status: unknown\n";
        break;
    }

    State_machine state_machine;
    state_machine.create_order();

    while (state_machine.current_status != order_status::delivered)
    {
        state_machine.advance_status();
    }

    
    return 0;
}
