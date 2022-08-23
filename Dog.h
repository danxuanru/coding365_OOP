#ifndef DOG_H
#define DOG_H

#include <iostream>
#include <cmath>
#include "Toy.h"

class Dog
{

private:
    std::string _name;
    double _weight;
    int _toyAmount;
    Toy *_toyCollections;

    // *add data
    int _toyAmount_string;
    std::string *_toyCollections_string;

    // move init function to private data
    void init(std::string name, double weight, int toyAmount, Toy *toyCollections, int toyAmount_string, std::string *toyCollections_string)
    {
        if (weight > 50 || weight < 10)
            throw std::string("This is not normal weight");

        if (name == "")
            throw std::string("Dog must have name!");

        _name = name;
        _weight = weight;
        _toyAmount = toyAmount;
        _toyAmount_string = toyAmount_string;
        _toyCollections = new Toy[_toyAmount];
        _toyCollections_string = new std::string[_toyAmount_string];
        for (int i = 0; i < _toyAmount; i++)
        {
            _toyCollections[i] = toyCollections[i];
        }
        for (int i = 0; i < _toyAmount_string; i++)
        {
            _toyCollections_string[i] = toyCollections_string[i];
        }
    }

public:
    Dog()
    { // initialization
        _name = "";
        _weight = 0;
        _toyAmount = 0;
        _toyCollections = NULL;
    }
    Dog(std::string name, double weight)
    {
        init(name, weight, 0, _toyCollections, 0, _toyCollections_string);
    }
    Dog(Dog const &other)
    {
        init(other._name, other._weight, 0, other._toyCollections, 0, other._toyCollections_string);
    }

    Dog &operator=(Dog const &other)
    {
        init(other._name, other._weight, 0, other._toyCollections, 0, other._toyCollections_string);
        return *this;
    }
    // add destructor
    ~Dog()
    {
        delete[] _toyCollections;
    }

    std::string getName() const
    {
        return _name;
    }
    double getWeight() const
    {
        return _weight;
    }

    // std::string getToy(int index) const
    // {
    //     return _toyCollections_string[index];
    // }
    Toy getToy(int index) const
    {
        if (index < 0 || index >= _toyAmount)
            throw std::string("Index must greater than 1!");

        return _toyCollections[index];
    }

    void addNewToy(Toy const &toyName)
    {
        _toyAmount++;
        Toy *new_toyCollections = new Toy[_toyAmount];
        for (int i = 0; i < _toyAmount - 1; i++)
        {
            new_toyCollections[i] = _toyCollections[i];
        }
        new_toyCollections[_toyAmount - 1] = toyName;
        delete[] _toyCollections;
        _toyCollections = new_toyCollections; // direct assign
    }

    void addNewToy(std::string newToyName)
    {
        _toyAmount_string++;
        std::string *new_toyCollections = new std::string[_toyAmount_string];
        for (int i = 0; i < _toyAmount_string - 1; i++)
        {
            new_toyCollections[i] = _toyCollections_string[i];
        }
        new_toyCollections[_toyAmount_string - 1] = newToyName;
        delete[] _toyCollections_string;
        _toyCollections_string = new_toyCollections;
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