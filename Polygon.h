#ifndef POLYGON_H
#define POLYGON_H
#include "Shape.h"
#include "MathVector.h"

class Polygon : public Shape
{
private:
    std::vector<MathVector> _vertex;

public:
    Polygon()
    {
        _name += "::polygon";
    }
    // getDim() ->  new parameter len
    Polygon(MathVector *input)
    {
        for (int i = 0; i < input->getDim(); i++)
        {
            _vertex.push_back(input[i]);
        }
        _name += "::polygon";
    }

    ~Polygon()
    {
    }

    double perimeter() override
    {
    }
    double area() override
    {
    }
};

#endif