#include "text_box.hpp"
#include <iostream>

int main()
{
    text_box parent_box{ 0, 0, 0, 0, "This is the parent box" };
    
    text_box tb1{ 25, 25, 200, 200, "My first text_box" };
    text_box tb2{ 225, 25, 200, 200, "My second text_box" };
    text_box tb3{ 25, 225, 200, 200, "My third text_box" };
    text_box tb4{ 225, 225, 200, 200, "My fourth text_box" };

    parent_box.add_child_element(&tb1);
    parent_box.add_child_element(&tb2);
    parent_box.add_child_element(&tb3);
    parent_box.add_child_element(&tb4);

    pointing_device p_device{ {30,30}, true };

    if (parent_box.list_child_elements().at(0)->on_click(p_device))
    {
        std::cout << "Success!\n";
    }
    else
        std::cout << "Failure!\n";
    
    return 0;
}
