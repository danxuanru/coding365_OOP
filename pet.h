#ifndef PET_H
#define PET_H
#include <iostream>

class Pet
{

protected:
    std::string _name;
    double _weight;

public:
    Pet()
    {
    }

    std::string getName()
    {
        return _name;
    }
    double getWeight()
    {
        return _weight;
    }

    // pure virtual function
    virtual void feed() = 0;
};

#endif