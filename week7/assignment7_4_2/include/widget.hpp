#ifndef UI_WIDGET_HPP
#define UI_WIDGET_HPP
#include <vector>

#include "ui_utilities.hpp"

class widget
{
public:
    widget(int x, int y) : position{ x,y } {}
    
    virtual bool on_click(const pointing_device& p_device) = 0;
    virtual bool on_focus(const pointing_device& p_device) = 0;
    virtual bool on_hover(const pointing_device& p_device) = 0;

    virtual void move_element(xy_pos xy) = 0;
    virtual void add_child_element(widget* widget_ptr) = 0;
    virtual void remove_child_element(const widget* widget_ptr) = 0;
    virtual std::vector<widget*>& list_child_elements() = 0;

    
    virtual ~widget() = default;

    xy_pos position{ 0,0 };
};

#endif
