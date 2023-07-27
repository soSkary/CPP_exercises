#include <iostream>
#include <string>
#include <vector>

//Exercises 1, 2 & 4
class animal
{
public:
    
    virtual std::string make_sound() const = 0;
    virtual int number_of_legs() const { return 0; }
    virtual bool breathes_air() const { return true; }

    virtual ~animal() = default;

private:
    std::string name;

};

class bird : public animal
{
public:
    
    std::string make_sound() const override { return sound; }
    int number_of_legs() const final { return 2; }
    bool breathes_air() const final { return true; }
    
    virtual ~bird() = default;

private:
    std::string name{ "bird" };
    std::string sound{ "chirp-chirp" };
};

class parrot : public bird
{
public:
    
    std::string make_sound() const final { return sound; }

private:
    std::string name{ "parrot" };
    std::string sound{ "kwa-kwaa" };
};

class dog : public animal
{
public:
    
    std::string make_sound() const final { return sound; }
    int number_of_legs() const final { return 4; }
    bool breathes_air() const { return true; }

private:
    std::string name{ "dog" };
    std::string sound{ "woof-woof" };
};

class fish : public animal
{
public:
    std::string make_sound() const final { return sound; }
    bool breathes_air() const final { return false; }

private:
    std::string name{ "fish" };
    std::string sound{ "blub-blub" };
};

//Exercise 3
void dance_animal_dance(const animal& a)
{
    std::cout << "I have " << a.number_of_legs() << " legs.\n";
    std::cout << (a.breathes_air() ? "I can " : "I can not ");
    std::cout << "breathe air.\n";
    std::cout << a.make_sound();
    std::cout << "\nWhat am I?\n\n";
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


    //Compiler doesn't let me create a vector of different animals.
    
    std::cout << "\nEXERCISE 5\n\nCreating a vector of animals, "
        "and calling dance_animal_dance() for all animals in vector\n\n";

    // std::vector<animal> gang;
    // gang.push_back(b);

    // for (const auto& individual : gang)
    // {
    //     dance_animal_dance(individual);
    // }

    //So I'll have to do it some othe way. This is one such, but maybe not the
    //best or safest. Create a vector of animal pointers, and pass those derefenced 
    //to the function instead.

    std::vector<const animal*> gang{ &b, &p, &d, &f };
    for (const auto& ptr : gang)
    {
        dance_animal_dance(*ptr);
    }

    return 0;
}
