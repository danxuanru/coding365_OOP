#ifndef CIRCLE_H
#define CIRCLE_H

#include "MathVector.h"
#include "Shape.h"

class Circle : public Shape
{
private:
    MathVector _center;
    double _redius;

public:
    Circle()
    {
        _name += "::circle";
    }
    Circle(double *input, double redius)
    {
        if (redius <= 0)
            throw std::string("redius must >0");

        _redius = redius;
        _center.expand(input[0]);
        _center.expand(input[1]);
        _name += "::circle";
    }
    ~Circle()
    {
    }
    // pure virtual function -> 'override'
    double perimeter() override
    {
        return 2 * _redius * M_PI;
    }
    double area() override
    {
        return _redius * _redius * M_PI;
    }
};

#endif