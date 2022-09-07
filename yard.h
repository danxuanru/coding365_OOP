#ifndef YARD_H
#define YARD_H
#include <vector>
#include "pet.h"
#include "cat.h"
#include "dog.h"

class Yard
{
private:
    std::vector<Pet *> _pets;
    void deep_copy(std::vector<Pet *> pet)
    {
        for (int i = 0; i < pet.size(); i++)
        {
            if (pet.at(i)->kind() == "CAT")
            {
                _pets.push_back(new Cat(pet.at(i)->name(), pet.at(i)->weight()));
            }
            else if (pet.at(i)->kind() == "DOG")
            {
                _pets.push_back(new Dog(pet.at(i)->name(), pet.at(i)->weight()));
            }
        }
    }

public:
    Yard() = default;
    // copy constructor
    Yard(Yard const &other)
    {
        deep_copy(other._pets);
    }
    // copy assignment
    Yard &operator=(Yard const &other)
    {
        deep_copy(other._pets);
        return *this;
    }
    ~Yard()
    {
        for (int i = 0; i < _pets.size(); i++)
            delete _pets.at(i);
    }
    void addPet(Pet *pet)
    {
        _pets.push_back(pet);
    }
    template <typename cond>
    std::vector<Pet *> getPetWithCondition(cond comp)
    {
        std::vector<Pet *> ans;
        for (int i = 0; i < _pets.size(); i++)
        {
            Pet *pet = _pets.at(i);
            if (comp(pet))
            {
                ans.push_back(pet);
            }
        }
        return ans;
    }
};

#endif