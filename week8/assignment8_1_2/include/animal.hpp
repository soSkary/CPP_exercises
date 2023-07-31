#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <string>
#include <string_view>

class animal
{
public:
    animal(const std::string& t, const std::string& n, const std::string& s)
        : type{ t }, name{ n }, sound{ s } {}
    animal(const std::string& t, const std::string& s)
        : type{ t }, name{}, sound{ s } {}

    virtual std::string make_sound() const = 0;
    virtual int number_of_legs() const { return 0; }
    virtual bool breathes_air() const { return true; }

    virtual ~animal() = default;

    std::string type;
    std::string name;
    std::string sound;

};

class bird : virtual public animal
{
public:
    bird() : animal{ "bird", "chirp-chirp" } {}
    bird(const std::string& n) : animal{ "bird", n, "chirp-chirp" } {}

    std::string make_sound() const override { return sound; }
    int number_of_legs() const final { return 2; }
    bool breathes_air() const final { return true; }

    virtual ~bird() = default;
};

class parrot : public bird
{
public:
    parrot() : animal{ "parrot", "kwa-kwaa" } {}
    parrot(const std::string& n) : animal{ "parrot", n, "kwa-kwaa" } {}
    
    std::string make_sound() const final { return sound; }

};

class dog : public animal
{
public:
    dog() : animal{ "dog","woof-woof" } {}
    dog(const std::string& n) : animal{ "dog", n, "woof-woof" } {}
    
    std::string make_sound() const final { return sound; }
    int number_of_legs() const final { return 4; }
    bool breathes_air() const { return true; }
};

class fish : public animal
{
public:
    fish() : animal{ "fish", "blub-blub" } {}
    fish(const std::string& n) : animal{ "fish", n, "blub-blub" } {}
    
    std::string make_sound() const final { return sound; }
    bool breathes_air() const final { return false; }
};


#endif
