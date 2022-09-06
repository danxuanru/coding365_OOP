#ifndef POLYGON_H
#define POLYGON_H
#include "Shape.h"
#include "MathVector.h"
#include "Triangle.h"

class Polygon : public Shape
{
private:
    std::vector<MathVector> _vertex;
    // std::vector<std::vector<MathVector>> _vertex;
    int _len;

public:
    Polygon()
    {
        _name += "::polygon";
    }
    // getDim() ->  new parameter len
    Polygon(MathVector *input, int len)
    {
        for (int i = 0; i < len; i++)
        {
            _vertex.push_back(input[i]);
        }
        _len = len;
        _name += "::polygon";
    }

    ~Polygon()
    {
    }

    double perimeter() override
    {
        double sum = 0;
        for (int i = 0; i < _len; i++)
        {
            // 	Subtraction of Vectors
            MathVector m = _vertex[i + 1] - _vertex[i];
            sum += m.length();
        }
        MathVector n = _vertex[_len - 1] - _vertex[0];
        sum += n.length();
        return sum;
    }
    double area() override
    {
        double sum = 0;
        for (int i = 0; i < _len - 2; i++) // len -> _vertex.size()
        {
            Triangle t(_vertex[i], _vertex[i + 1], _vertex[i + 2]);
            sum += t.area();
        }
        return sum;
    }
};

#endif