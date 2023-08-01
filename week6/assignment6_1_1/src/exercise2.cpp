#include "exercise2.hpp"

#include <iostream>




void State_machine::print_status() const
{
    switch (current_status)
    {
    case order_status::ordered:
        std::cout << "Order status: ordered\n";
        break;
        case order_status::packaged:
        std::cout << "Order status: packaged\n";
        break;
        case order_status::preparing_shipment:
        std::cout << "Order status: preparing shipment\n";
        break;
        case order_status::shipped:
        std::cout << "Order status: shipped\n";
        break;
        case order_status::delivered:
        std::cout << "Order status: delivered\n";
        break;
    }
}

void State_machine::create_order()
{
    current_status = order_status::ordered;
    std::cout << "Order created.\n";
}

void State_machine::advance_status()
{
    if (current_status < order_status::delivered)
    {
        std::cout << "Current: ";
        print_status();

        switch (current_status)
        {
        case order_status::ordered:
            current_status = order_status::packaged;
            break;
        case order_status::packaged:
            current_status = order_status::preparing_shipment;
            break;
        case order_status::preparing_shipment:
            current_status = order_status::shipped;
            break;
         case order_status::shipped:
            current_status = order_status::delivered;
            break;
         default:
             break;
        }

        std::cout << "Advancing to: ";
        print_status();
    }
    else
    {
        std::cout << "Order already delivered: ";
        print_status();
    }
}
