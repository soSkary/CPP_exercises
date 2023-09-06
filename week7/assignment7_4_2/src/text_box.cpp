#include "text_box.hpp"

#include <algorithm>
#include <iostream>
#include <stdexcept>

text_box::text_box(int x, int y, int w, int h, const std::string& text)
    : widget{ x,y }, width{ w }, height{ h }, value{ text }
{
    static int new_id{ 0 };
    id = new_id++;
}

bool text_box::on_click(const pointing_device& p_device)
{
    if (on_focus(p_device) && p_device.is_pressed)
        return true;
    else
        return false;

}

bool text_box::on_focus(const pointing_device& p_device)
{
    if (p_device.position.x >= position.x
        && p_device.position.x <= position.x + width
        && p_device.position.y >= position.y
        && p_device.position.y <= position.y + height)
    {
        background_color = color::blue;
        return true;
    }
    else
    {
        background_color = color::white;
        return false;
    }
}

bool text_box::on_hover(const pointing_device& p_device)
{
    if (p_device.position.x >= position.x
        && p_device.position.x <= position.x + width
        && p_device.position.y >= position.y
        && p_device.position.y <= position.y + height
        && !p_device.is_pressed)
    {
        background_color = color::yellow;
        return true;
    }
    else
    {
        background_color = color::white;
        return false;
    }
}

void text_box::move_element(xy_pos xy)
{
    position = xy;
}

void text_box::add_child_element(widget* widget_ptr)
{
    children.push_back(widget_ptr);
}

void text_box::remove_child_element(const widget* widget_ptr)
{
    auto child_to_remove{ std::find(children.begin(), children.end(), widget_ptr) };
    if (child_to_remove != std::end(children))
    {
        children.erase(child_to_remove);
    }
    else
    {
        throw std::runtime_error("Couldn't find child");
    }
}

std::vector<widget*>& text_box::list_child_elements()
{
    return children;
}

void text_box::input_text()
{
    std::cout << "Please input text here:\n";
    std::getline(std::cin, value);
}

