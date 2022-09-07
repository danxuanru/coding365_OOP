#ifndef CAT_H
#define CAT_H

#include "pet.h"

class Cat : public Pet
{

private:
    static int _amount;

public:
    Cat()
    {
    }
    ~Cat()
    {
        std::cout << "cat destructor\n";
        _amount -= 1;
    }
    // child class's constructor initialization list [ : Parent_class(input_data..) ]
    Cat(std::string name, double weight) : Pet("CAT", name, weight)
    {
        if (weight < 2 || weight > 6)
            throw std::range_error("weight should >2 and <6");
        // _name = name;
        // _weight = weight;
        _amount += 1;
    }

    static int amount()
    {
        return _amount;
    }

    void feed() override
    {
        if (weight() + 0.2 > 6)
            throw std::out_of_range("weight exceeds thw limit 6");
        else
            //_weight += 0.2;
            grow(0.2);
    }
};
// static data need initialization
int Cat::_amount = 0;

#endif