#ifndef EXERCISE_1
#define EXERCISE_1

#include <random>

enum class status
{
    success,
    loading_error,
    saving_error,

    max_status
};

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
status random_status_code(status max_status);

#endif
