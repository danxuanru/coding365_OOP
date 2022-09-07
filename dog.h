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
        _amount++;
    }
    ~Dog() override
    {
        // std::cout << "Dog destructor\n";
        _amount--;
    }
    Dog(std::string name, double weight) : Pet("DOG", name, weight)
    {
        if (weight < 10 || weight > 50)
            throw std::range_error("Range ERROR!");
        _amount++;
    }
    void feed() override
    {
        if (weight() + 0.8 > 50)
            throw std::out_of_range("Out of Range!");
        grow(0.8);
    }
    static int amount()
    {
        return _amount;
    }
};
int Dog::_amount = 0;
#endif