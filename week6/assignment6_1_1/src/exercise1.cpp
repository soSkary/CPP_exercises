#include "exercise1.hpp"

status random_status_code(status max_status)
{
    int randomly_distributed{ std::uniform_int_distribution{0, static_cast<int>(max_status) - 1}(Random::mt) };
    return static_cast<status>(randomly_distributed);
}
