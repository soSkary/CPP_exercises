#ifndef EXERCISE_1
#define EXERCISE_1

#include <array>
#include <random>

static constexpr std::size_t status_count{ 3 };

enum class status
{
    success,
    loading_error,
    saving_error
};

static constexpr std::array<status, status_count> all_statuses
{ status::success, status::loading_error, status::saving_error };

namespace Random
{

    //Seed and generate a PRNG Mersenne Twister
    inline std::mt19937 generate()
    {
        std::random_device rd{};

        std::seed_seq ss{ rd(),rd(),rd(),rd(),rd(),rd(),rd(),rd() };

        return std::mt19937{ ss };
    }

    //An instance of the generated Twister
    inline std::mt19937 mt{ generate() };

}

//A function to return a random status code
status random_status_code();

#endif
