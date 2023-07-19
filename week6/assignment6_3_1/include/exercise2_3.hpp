#ifndef EXERCISE2_3_HPP
#define EXERCISE2_3_HPP

class wings
{
public:
    wings();
    ~wings();

    void what_are_you();
};

class eyes
{
public:
    eyes();
    ~eyes();

    void what_are_you();
};

class animal
{
public:
    animal();
    ~animal();

    void what_are_you();
};

class bird : public animal
{
public:
    bird();
    ~bird();

    void what_are_you();

    wings w;
    eyes e; //this could be inside animals as well, but not all animals have eyes
};

class parrot : public bird
{
public:
    parrot();
    ~parrot();

    // void what_are_you();

};

class dog : public animal
{
public:
    dog();
    ~dog();

    void what_are_you();

    eyes e; //this could be inside animals as well, but not all animals have eyes
};


#endif
