#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <vector>

class Shape
{
private:   // other object both can't be read or modified
protected: // allow Derived class to read , but couldn't be modified
    std::string _name;

public:
    Shape()
    {
        std::cout << "Shape default constructor" << std::endl;
        _name = "shape";
    }
    ~Shape()
    {
    }

    std::string getName()
    {
        return _name;
    }
    void setName(std::string input)
    {
        _name = input;
    }

    // unsure how to implement
    // double perimeter()
    // {
    // }
    // double area()
    // {
    // }

    // define a pure virtual function
    // Shape s3;   // unable to do this
    virtual double perimeter() = 0;
    virtual double area() = 0;
};

#endif