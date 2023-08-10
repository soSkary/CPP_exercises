#ifndef ANIMALS_HPP
#define ANIMALS_HPP

#include <iostream>
#include <string>


// class animal
// {
// public:
//     animal(const std::string& n, const std::string& s) : name{ n }, sound{ s } {}
    
//     std::string make_sound();
//     int number_of_legs() const;
//     bool breathes_air() const;

//     std::string name;
//     std::string sound;

// };

class bird 
{
public:
    bird() : name{ "bird" }, sound{ "chirp-chirp" } {}

    constexpr std::string make_sound() const { return sound; }
    constexpr int number_of_legs() const { return 2; }
    constexpr bool breathes_air() const { return true; }
    
    std::string name;
    std::string sound;
};

class parrot
{
public:
    parrot() : name{ "parrot" }, sound{ "kwaa-kwaa" } {}
    parrot(const parrot&) = default;
    
    constexpr std::string make_sound() const { return sound; }
    constexpr int number_of_legs() const { return 2; }
    constexpr bool breathes_air() const { return true; }
    
    std::string name;
    std::string sound;

};

class dog
{
public:
    dog() : name{ "dog" }, sound{ "woof-woof" } {}
    dog(const dog&) = default;
    
    constexpr std::string make_sound() const { return sound; }
    constexpr int number_of_legs() const  { return 4; }
    constexpr bool breathes_air() const { return true; }

    std::string name;
    std::string sound;
};

class fish
{
public:
    fish() : name{ "fish" }, sound{ "blub-blub" } {}
    fish(const fish&) = default;
    
    constexpr std::string make_sound() const { return sound; }
    constexpr int number_of_legs() const  { return 0; }
    constexpr bool breathes_air() const { return false; }

    std::string name;
    std::string sound;    
};

#endif
