#ifndef DOG_H
#define DOG_H

#include "pet.h"

class Dog : public Pet
{

private:
public:
    Dog()
    {
    }
    Dog(std::string name, double weight)
    {
        if (weight < 10 || weight > 50)
            throw std::range_error("weight should >10 and <50");
        _name = name;
        _weight = weight;
    }

    // pure virtual function
    void feed() override
    {
        _weight += 0.8;
        if (_weight > 50)
            throw std::out_of_range("weight exceeds thw limit 50");
    }
};

#endif