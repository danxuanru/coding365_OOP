#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "MathVector.h"
#include <cmath>
#include "Shape.h"

class Triangle : public Shape
{
private:
    MathVector _x, _y, _z;

public:
    Triangle()
    {
    }
    Triangle(MathVector const &x, MathVector const &y, MathVector const &z)
    {
        _x = x;
        _y = y;
        _z = z;
    }
    ~Triangle()
    {
    }

    double perimeter()
    {
        double result = 0;
        MathVector r, u, w;
        r = _y - _x;
        u = _z - _y;
        w = _z - _x;
        result = r.length() + u.length() + w.length();
        return result;
    }
    double area()
    {
        double s, result;
        double a, b, c;
        // convert side length from MathVector to double
        a = (_y - _x).length();
        b = (_z - _y).length();
        c = (_z - _x).length();
        s = perimeter() / 2;
        result = sqrt(s * (s - a) * (s - b) * (s - c));
        return result;
    }
};

#endif