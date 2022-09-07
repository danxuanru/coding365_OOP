#ifndef PET_H
#define PET_H
#include <iostream>

class Pet
{

private:
    std::string _kind;
    std::string _name;
    double _weight;
    // static data
    static int _amount;

protected:
    // only can use in child class
    void grow(double add)
    {
        _weight += add;
    }

    // std::string _name;
    // double _weight;

public:
    Pet()
    {
        _name = "";
        _weight = 0;
    }
    virtual ~Pet()
    {
        std::cout << "pet destructor\n";
        _amount -= 1;
    }

    // constructor initialization list [ : private_data(input_data) ]
    Pet(std::string const kind, std::string const name, double const weight) : _kind(kind), _name(name), _weight(weight)
    {
        _amount += 1;
    }

    static int amount() // get static data
    {
        return _amount;
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
// static data need initialization
// define class (static data create) -> initialization -> instantiation
int Pet::_amount = 0;

#endif