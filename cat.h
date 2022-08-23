#ifndef CAT_H
#define CAT_H

#include "pet.h"

class Cat : public Pet
{
private:
public:
    Cat()
    {
    }
    Cat(std::string name, double weight)
    {
        if (weight < 2 || weight > 6)
            throw std::range_error("weight should >2 and <6");
        _name = name;
        _weight = weight;
    }

    void feed() override
    {
        _weight += 0.2;
        if (_weight > 6)
            throw std::out_of_range("weight exceeds thw limit 6");
    }
};

#endif