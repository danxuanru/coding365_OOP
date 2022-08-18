#ifndef TOY_H
#define TOY_H

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

    std::string getName() const
    {
        return _toyName;
    }
};

#endif