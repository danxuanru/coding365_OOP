#ifndef DOG_H
#define DOG_H

#include "pet.h"

class Dog : public Pet
{

private:
    static int _amount;

public:
    Dog()
    {
    }
    ~Dog()
    {
        std::cout << "dog destructor\n";
        _amount -= 1;
    }
    // child class's constructor initialization list [ : Parent_class(input_data..) ]
    Dog(std::string name, double weight) : Pet("DOG", name, weight)
    {
        if (weight < 10 || weight > 50)
            throw std::range_error("weight should >10 and <50");
        // _name = name;
        // _weight = weight;
        _amount += 1;
    }
    static int amount()
    {
        return _amount;
    }

    // pure virtual function
    void feed() override
    {
        if (weight() + 0.8 > 50)
            throw std::out_of_range("weight exceeds thw limit 50");
        else
            //_weight += 0.8;
            grow(0.8);
    }
};
// static data need initialization
int Dog::_amount = 0;

#endif