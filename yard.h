#ifndef YARD_H
#define YARD_H

#include "pet.h"
#include <vector>

class Yard
{

private:
    std::vector<Pet *> _pets;

public:
    Yard()
    {
    }
    ~Yard()
    {
        for (int i = 0; i < _pets.size(); i++)
            delete _pets[i];
    }

    void addPet(Pet *pet)
    {
        _pets.push_back(pet);
    }

    // template function: different datatype use same function
    template <typename Condition>
    std::vector<Pet *> getPetWithCondition(Condition comp)
    {
        std::vector<Pet *> pet_in_condition;
        // for (int i = 0; i < _pets.size(); i++)
        //     Pet *pet = _pets.at(i);
        for (Pet *pet : _pets) // for each
        {
            if (comp(pet) == true)
                pet_in_condition.push_back(pet);
        }
        return pet_in_condition;
    }
};

#endif