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

    std::string name()
    {
        return _name;
    }
    double weight()
    {
        return _weight;
    }

    // pure virtual function
    virtual void feed() = 0;
};

#endif