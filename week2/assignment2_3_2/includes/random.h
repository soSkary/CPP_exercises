#ifndef RANDOM_H
#define RANDOM_H

#include <random>

namespace Random
{
    //Prepare random stuff
    static inline std::random_device rd;
    static inline std::seed_seq ss{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
    static inline std::mt19937 mt{ss};

    
    static inline std::uniform_int_distribution random_timestamp{1, 10000};
    static inline std::uniform_int_distribution random_int{0, 9};
    static inline std::uniform_real_distribution<float> random_float_0_1{0.0f, 1.0f};
    


}

#endif
