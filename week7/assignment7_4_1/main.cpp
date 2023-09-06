#include <iostream>
#include <string>
#include <vector>

//Exercises 1, 2 & 4
class animal
{
public:
    animal(const std::string& n, const std::string& s) : name{ n }, sound{ s } {}
    
    virtual std::string make_sound() const = 0;
    virtual int number_of_legs() const { return 0; }
    virtual bool breathes_air() const { return true; }

    virtual ~animal() = default;

    std::string name;
    std::string sound;

};

class bird : virtual public animal
{
public:
    bird() : animal{ "bird", "chirp-chirp" } {}
    std::string make_sound() const override { return sound; }
    int number_of_legs() const final { return 2; }
    bool breathes_air() const final { return true; }
    
    virtual ~bird() = default;
};

class parrot : public bird
{
public:
    parrot() : animal{ "parrot", "kwa-kwaa" } {}
    std::string make_sound() const final { return sound; }

};

class dog : public animal
{
public:
    dog() : animal{ "dog","woof-woof" } {}
    std::string make_sound() const final { return sound; }
    int number_of_legs() const final { return 4; }
    bool breathes_air() const { return true; }
};

class fish : public animal
{
public:
    fish() : animal{ "fish", "blub-blub" } {}
    std::string make_sound() const final { return sound; }
    bool breathes_air() const final { return false; }
};

//Exercise 3
void dance_animal_dance(const animal& a)
{
    std::cout << "I have " << a.number_of_legs() << " legs.\n";
    std::cout << (a.breathes_air() ? "I can " : "I can not ");
    std::cout << "breathe air.\n";
    std::cout << a.make_sound();
    std::cout << "\nWhat am I?\n\n";
    std::cout << "A " << a.name << "\n\n";
}

int main()
{
    bird b;
    parrot p;
    dog d;
    fish f;


    dance_animal_dance(b);
    dance_animal_dance(p);
    dance_animal_dance(d);
    dance_animal_dance(f);


    
    std::cout << "\nEXERCISE 5\n\nCreating a vector of animals, "
        "and calling dance_animal_dance() for all animals in vector\n\n";

    // Compiler doesn't let me create a vector of different animals, as the base 
    // class has one pure virtual function
    // virtual std::string make_sound() const = 0;

    // std::vector<animal> gang{ b,p,d,f };

    // for (const auto& individual : gang)
    // {
    //     dance_animal_dance(individual);
    // }

    // So I'll have to do it some othe way. This is one such, but maybe not the
    // best or safest. Create a vector of animal pointers, and pass those derefenced 
    // to the function instead.

    std::vector<const animal*> ptr_gang{ &b, &p, &d, &f };
    for (const auto& ptr : ptr_gang)
    {
        dance_animal_dance(*ptr);
    }

    return 0;
}
