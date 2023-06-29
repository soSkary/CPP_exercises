#include <random>


//Create a random device for seeding
inline static std::random_device rd;
//Get 8 random integers for our seed
inline static std::seed_seq ss{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
//Initialize Mersenne Twister with the seeder
inline static std::mt19937 mt{ ss };
//Create a reusable random number generator for numbers between 0 and 3
inline static std::uniform_int_distribution random_0_3{0, 3};
//Create a reusable random number generator for numbers between 0 and 9
inline static std::uniform_int_distribution random_0_9{0, 9};
