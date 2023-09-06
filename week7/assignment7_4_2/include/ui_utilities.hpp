#ifndef UI_UTILITIES_HPP
#define UI_UTILITIES_HPP

enum class color
{
    black,
    white,
    blue,
    red,
    yellow
};

struct xy_pos
{
    int x;
    int y;
};

struct pointing_device
{
    xy_pos position{0,0};
    bool is_pressed{false};
};

#endif
