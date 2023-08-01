#include "exercise1.hpp"

status random_status_code()
{
    int randomly_distributed{ std::uniform_int_distribution{0, static_cast<int>(status_count) - 1}(Random::mt) };
    return all_statuses.at(randomly_distributed);
}
