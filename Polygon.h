#ifndef POLYGON_H
#define POLYGON_H
#include "Shape.h"
#include "MathVector.h"
#include "Triangle.h"

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
        double sum = 0;
        std::cout << _vertex.size() << std::endl;

        for (int i = 0; i < _vertex.size(); i++)
        {
            Triangle t(_vertex[i], _vertex[i + 1], _vertex[i + 2]);
            sum += t.area();
        }
        return sum;
    }
};

#endif