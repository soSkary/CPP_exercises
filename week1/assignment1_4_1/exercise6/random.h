#ifndef RANDOM_MT_H
#define RANDOM_MT_H

#include <chrono>
#include <random>

// This header-only Random namespace implements a self-seeding Mersenne Twister
// It can be included into as many code files as needed (The inline keyword avoids ODR violations)
namespace Random
{
	// Returns a seeded Mersenne Twister
	// Note: we'd prefer to return a std::seed_seq (to initialize a std::mt19937), but std::seed can't be copied, so it can't be returned by value.
	// Instead, we'll create a std::mt19937, seed it, and then return the std::mt19937 (which can be copied).
	inline std::mt19937 generate()
	{
		std::random_device rd{};

		// Create seed_seq with high-res clock and 7 random numbers from std::random_device
		std::seed_seq ss{
			static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()),
			rd(), rd(), rd(), rd(), rd(), rd(), rd() };

		return std::mt19937{ ss };
	}

	// Here's our global std::mt19937 object.
	// The inline keyword means we only have one global instance for our whole program.
	inline std::mt19937 mt{ generate() }; // generates a seeded std::mt19937 and copies it into our global object

	// Generate a random number between [min, max] (inclusive)
	inline int get(int min, int max)
	{
		std::uniform_int_distribution die{ min, max };
		return die(mt);
	}
};

#endif
