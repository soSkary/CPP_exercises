#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <type_traits>

struct test_int128
{
    int64_t a;
    int64_t b;
};

constexpr static uint8_t POISONED       { 0b1 };
constexpr static uint8_t PARALYZED      { 0b10 };
constexpr static uint8_t BLIND          { 0b100 };
constexpr static uint8_t BERSERK        { 0b1000 };
constexpr static uint8_t HASTE          { 0b10000 };
constexpr static uint8_t REGENERATE     { 0b100000 };
constexpr static uint8_t DAMAGE_BOOST   { 0b1000000 };
constexpr static uint8_t REFLECT        { 0b10000000 };

//A template function to print bits of variables up to 64-bit size
template <typename T>
void print_bits(const T& value)
{
    
    if (sizeof(value) > sizeof(uint64_t))
    {
        std::cout << "Can't print bits for value's over 64 bits\n";
        return;
    }

    	
    std::cout << "0b";
 
    for (int i{ sizeof(std::decay_t<T>) * 8 - 1 }; i >= 0; --i)
    {
        // Bitwise 1 and the i-position of value, so if value has 1, print 1 otherwise print 0
        if (value & (1ULL << i))
            std::cout << '1';
        else
            std::cout << '0';
        //add a ' after every byte (8-bits) to increase readability
        if ((i % 8 == 0) && (i != 0))
            std::cout << '\'';
    }

    std::cout << '\n';
}

//Exercise 1
template <typename T>
bool nth_bit_is_set(const T& value, uint8_t bit_nr)
{
    return (value & (1ULL << bit_nr));
}

//Exercise 2
template <typename T>
void swap_byte_order(T& value)
{
    static_assert(std::is_integral_v<std::decay_t<T&>>);

    //Reinterpret cast an 8bit integer to value, and use it to divide the
    //variable in to blocks of bytes
    uint8_t* ptr_begin{ reinterpret_cast<uint8_t*>(&value) };
    uint8_t* ptr_end{ ptr_begin + (sizeof(value)-1) };

    while (ptr_begin < ptr_end)
    {
        std::swap(*ptr_begin, *ptr_end);
        ++ptr_begin;
        --ptr_end;
    }

}

//Exercise 3
//Using a bitmask and flags

using status_effects = uint8_t;
void print_character_status_effects(status_effects character)
{
    std::cout << "Status effects affecting character:\n";
    if (character & POISONED)
    {
        std::cout << "poison\n";
    }
    if (character & PARALYZED)
    {
        std::cout << "paralyzed\n";
    }
    if (character & BLIND)
    {
        std::cout << "blind\n";
    }
    if (character & BERSERK)
    {
        std::cout << "berserk\n";
    }
    if (character & HASTE)
    {
        std::cout << "haste\n";
    }
    if (character & REGENERATE)
    {
        std::cout << "regenerate\n";
    }
    if (character & DAMAGE_BOOST)
    {
        std::cout << "damage boost\n";
    }
    if (character & REFLECT)
    {
        std::cout << "reflect\n";
    }
}

//Exercise 4
//Check if combinations of flags set, and change flags and/or print messages
void check_character_status_effects(status_effects& character)
{
    //Check if PARALYZED and HASTE
    if ((character & PARALYZED) && (character & HASTE))
    {
        //turn HASTE off
        character &= ~HASTE;
        std::cout << "Oh no! Haste was nullified, as you're paralyzed and can't move!\n";
    }

    //Check if REGENERATE and POISONED
    if ((character & REGENERATE) && (character & POISONED))
    {
        //turn POISONED off
        character &= ~POISONED;
        std::cout << "Regeneration cures poison!\n";
    }

    //Check if POISONED, PARALYZED and BLIND
    if ((character & POISONED) && (character & PARALYZED) && (character & BLIND))
    {
        std::cout << "You're in trouble my friend!\n";
    }
}
//Exercise 5
//Create a bitmask from a std::string, every ',' represents a 1, otherwise 0
uint64_t create_comma_mask(const std::string& value)
{
    if (value.size() > 64)
    {
        std::cout << "Can't create a mask bigger than 64, returning 0\n";
        return 0;
    }

    //create a bitmask with initial value of 0
    uint64_t bitmask{ 0 };

    //then in a loop if comma found, shift the position in the mask to a one

    for (std::size_t i{ 0 }; i < 64 && i < value.size(); ++i)
    {
        if (value.at(i) == ',')
        {
            bitmask |= (1ULL << i);
        }
    }

    return bitmask;
}

int main()
{
    //Exercise 1
    std::cout << "Exercise 1\n\n";
    uint16_t test_a{ 0b0001111100101010 };
    uint64_t test_b{ 0b0101001011010010110101101010010101100110010010010110110101010101 };

    std::cout << "These should be true:\n";
    std::cout << std::boolalpha << "bit 1 is set: " << nth_bit_is_set(test_a, 1)
        << "\nbit 3 is set: " << nth_bit_is_set(test_a, 3);
    std::cout << "\nThese should be false:\n";
    std::cout << std::boolalpha << "bit 0 is set: " << nth_bit_is_set(test_a, 0)
        << "\nbit 2 is set: " << nth_bit_is_set(test_a, 2) << '\n';

    
    //Exercise 2
    std::cout << "\nExercise 2\n\n";
    std::cout << std::hex;
    std::cout << "test_a before swap: " << test_a << '\n';
    swap_byte_order(test_a);
    std::cout << "test_a after swap: " << test_a << '\n';
    swap_byte_order(test_a);
    std::cout << "test_a back to initial: " << test_a << '\n';

    std::cout << "test_b before swap: " << test_b << '\n';
    swap_byte_order(test_b);
    std::cout << "test_b after swap: " << test_b << '\n';
    swap_byte_order(test_b);
    std::cout << "test_b back to initial: " << test_b << '\n';

    //Exercise 3
    std::cout << "\nExercise 3\n\n";
    status_effects character1{ 0b01010101 };

    print_character_status_effects(character1);

    //Exercise 4
    std::cout << "\nExercise 4\n\n";

    //set paralysis and regeneration
    character1 |= (PARALYZED | REGENERATE);
    std::cout << "Round1:\n\n";
    print_character_status_effects(character1);
    check_character_status_effects(character1);

    std::cout << "\nRound2:\n\n";
    print_character_status_effects(character1);
    check_character_status_effects(character1);
    
    character1 |= POISONED;
    character1 &= ~REGENERATE;
    std::cout << "\nRound3 (add poison and remove regeneration in before):\n\n";
    print_character_status_effects(character1);
    check_character_status_effects(character1);

    //Exercise 5
    std::cout << "\nExercise 5\n\n";
    std::string comma_string{ "01,34,6,890,23456,89,123456789,1" };
    auto bitmask{ create_comma_mask(comma_string) };

    std::cout << "Should print:\n"
        << "0b00000000'00000000'00000000'00000000'01000000'00010010'00001000'10100100\n";
    
    print_bits(bitmask);

    std::string comma_string2{ "01,34,6,890,23456,89,123456789,100000000,,,,,,,,00000000,,,,,,,," };
    auto bitmask2{ create_comma_mask(comma_string2) };

    std::cout << "Should print:\n"
        << "0b11111111'00000000'11111111'00000000'01000000'00010010'00001000'10100100\n";

    
    print_bits(bitmask2);
    
    std::string comma_string3{ ",0000000,,000000,,,00000,,,,0000,,,,,000,,,,,,00,,,,,,,0,,,,,,,," };
    auto bitmask3{ create_comma_mask(comma_string3) };

    std::cout << "Should print:\n"
        << "0b11111111'01111111'00111111'00011111'00001111'00000111'00000011'00000001\n";
    print_bits(bitmask3);

    
    std::string user_input;
    std::cout << "Please input comma string to convert to bitmask:\n";
    std::getline(std::cin, user_input);

    auto bitmask_user{ create_comma_mask(user_input) };
    print_bits(bitmask_user);

    std::cout << '\n';

    return 0;
}
