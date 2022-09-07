#ifndef PET_H
#define PET_H
#include <iostream>
class Pet
{
protected:
    void grow(double r)
    {
        _weight += r;
    }

private:
    std::string _kind;
    std::string _name;
    double _weight;
    static int _amount;
public:
    Pet()
    {
        _amount++;
    };
    Pet(std::string kind, std::string name, double weight) : _kind(kind), _name(name), _weight(weight)
    {
        _amount++;
    }
    virtual ~Pet()
    {
        // std::cout << "Pet destructor\n";
        _amount--;
    }
    std::string name() const
    {
        return _name;
    }
    double weight() const
    {
        return _weight;
    }
    static int amount()
    {
        return _amount;
    }
    std::string kind() const
    {
        return _kind;
    }
    virtual void feed() = 0;
};
int Pet::_amount = 0;
#endif