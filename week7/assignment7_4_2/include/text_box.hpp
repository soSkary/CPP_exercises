#ifndef UI_TEXT_BOX_HPP
#define UI_TEXT_BOX_HPP

#include "ui_utilities.hpp"
#include "widget.hpp"

#include <string>

class text_box : public widget
{
public:
    text_box(int x, int y, int w, int h, const std::string& text);
    

    bool on_click(const pointing_device& p_device) final;
    bool on_focus(const pointing_device& p_device) final;
    bool on_hover(const pointing_device& p_device) final;

    void move_element(xy_pos xy) final;
    
    void add_child_element(widget* widget_ptr) final;
    void remove_child_element(const widget* widget_ptr) final;
    std::vector<widget*>& list_child_elements() final;

    void input_text();

private:
    bool clicked{ false };
    int width{ 0 };
    int height{ 0 };
    unsigned int id{ 0 };
    std::string value{ "Input text here" };
    color background_color{ color::white };
    std::vector<widget*> children;

};

#endif
