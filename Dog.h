#ifndef DOG_H
#define DOG_H

#include <iostream>
#include "Toy.h"
#include <vector>

class Dog
{

private:
    std::string _name;
    double _weight;
    std::vector<Toy> _toyCollections;

    // init function
    void init(std::string name, double weight, std::vector<Toy> toyCollections)
    {
        _name = name;
        _weight = weight;
        _toyCollections = toyCollections; // direct assign
    }

public:
    Dog()
    {
        _name = "";
        _weight = 0;
        // vector.clear()
        _toyCollections.clear();
    }
    Dog(std::string name, double weight)
    {
        if (name == "")
            throw std::string("Dog must have name!");
        if (weight > 50 || weight < 10)
            throw std::string("Out of scope!");

        init(name, weight, _toyCollections);
    }
    Dog(Dog const &other)
    {
        init(other._name, other._weight, other._toyCollections);
    }

    Dog &operator=(Dog const &other)
    {
        init(other._name, other._weight, other._toyCollections);
        return *this;
    }
    ~Dog()
    {
        // no need to delete memory space
    }

    std::string getName() const
    {
        return _name;
    }
    double getWeight() const
    {
        return _weight;
    }

    Toy getToy(int index) const
    {
        if (index < 0)
            throw std::string("Index must > 0!");
        if (index >= _toyCollections.size())
            throw std::string("index out of scope");

        // vector.at()
        return _toyCollections.at(index);
    }

    void addNewToy(Toy const &toyName)
    {
        // vector.push_back()
        _toyCollections.push_back(toyName);
    }

    bool isHeavierThan(Dog const &other) const
    {
        if (_weight > other._weight)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

#endif