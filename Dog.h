#include <math.h>
// using namespace std;

class Toy
{
private:
    std::string _toyName;

public:
    Toy()
    {
    }
    Toy(std::string name)
    {
        _toyName = name;
    }

    // Toy &operator=(Toy const &other)
    // {
    //     _toyName = other._toyName;
    //     return *this;
    // }

    std::string getName() const
    {
        return _toyName;
    }
};

class Dog
{

private:
    std::string _name;
    double _weight;
    int _toyAmount;
    Toy *_toyCollections;

public:
    // Constructor
    Dog()
    { // initialization
        _toyAmount = 0;
        _toyCollections = new Toy[_toyAmount];
    }
    Dog(std::string name, double weight)
    {
        if (weight >= 10 && weight <= 50)
        {
            _name = name;
            _weight = weight;
            _toyAmount = 0;
            _toyCollections = new Toy[_toyAmount];
        }
    }
    /* copy constructor */
    Dog(Dog const &other)
    {
        _name = other._name;
        _weight = other._weight;
        _toyAmount = other._toyAmount;
        _toyCollections = other._toyCollections;
    }

    /* copy assignment */
    Dog &operator=(Dog const &other)
    {
        _name = other._name;
        _weight = other._weight;
        _toyAmount = other._toyAmount;
        _toyCollections = other._toyCollections;
        return *this;
    }

    // Getter
    std::string getName()
    {
        return _name;
    }
    double getWeight()
    {
        return _weight;
    }

    Toy getToy(int index) const
    {
        return _toyCollections[index];
    }

    void addNewToy(Toy const &toyName)
    {
        // copy old array
        Toy *old_toyCollections = new Toy[_toyAmount];
        for (int i = 0; i < _toyAmount; i++)
        {
            old_toyCollections[i] = _toyCollections[i];
        }
        delete[] _toyCollections;
        _toyAmount++;

        // create new array
        _toyCollections = new Toy[_toyAmount];
        for (int i = 0; i < _toyAmount - 1; i++)
        {
            _toyCollections[i] = old_toyCollections[i];
        }
        _toyCollections[_toyAmount - 1] = toyName;
        delete[] old_toyCollections;
    }

    void collection()
    {
        for (int i = 0; i < _toyAmount; i++)
        {
            std::cout << _toyCollections[i].getName() << endl;
            std::cout << typeid(_toyCollections[i]).name() << endl;
        }
    }

    /* true if heavier than (>) other */
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
