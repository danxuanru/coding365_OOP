#include <iostream>
using namespace std;

class Dog
{

private:
    string _name;
    double _weight;
    int _toyAmount;
    string *_toyCollections;

public:
    // Constructor
    Dog()
    {
        _toyAmount = 0;
        _toyCollections = new string[_toyAmount];
    }
    Dog(string name, double weight)
    {
        _name = name;
        _weight = weight;
        _toyAmount = 0;
        _toyCollections = new string[_toyAmount];
    }
    // Getter
    string getName()
    {
        return _name;
    }
    double getWeight()
    {
        return _weight;
    }

    string getToy(int index)
    {
        return _toyCollections[index];
    }

    void addNewToy(string toyName)
    {
        // copy old array
        string *old_toyCollections = new string[_toyAmount];
        for (int i = 0; i < _toyAmount; i++)
        {
            old_toyCollections[i] = _toyCollections[i];
        }
        delete[] _toyCollections;
        _toyAmount++;

        // create new array
        _toyCollections = new string[_toyAmount];
        for (int i = 0; i < _toyAmount - 1; i++)
        {
            _toyCollections[i] = old_toyCollections[i];
        }
        _toyCollections[_toyAmount - 1] = toyName;
        delete[] old_toyCollections;
    }
};