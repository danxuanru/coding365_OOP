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
        _amount++;
    }
    ~Cat() override
    {
        // std::cout << "Cat destructor\n";
        _amount--;
    }
    Cat(std::string name, double weight) : Pet("CAT", name, weight)
    {
        if (weight < 2 || weight > 6)
            throw std::range_error("Range ERROR!");
        _amount++;
    }
    void feed() override
    {
        if (weight() + 0.2 > 6)
            throw std::out_of_range("Out of Range!");
        grow(0.2);
    }
    static int amount()
    {
        return _amount;
    }
};
int Cat::_amount = 0;
#endif