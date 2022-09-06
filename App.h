// Interface
#ifndef APP_H
#define APP_H
#include "Shape.h"
#include <algorithm>

bool compare(Shape *i, Shape *j)
{
    return i->area() < j->area();
}

class App
{

private:
    // Inheritance use *pointer
    std::vector<Shape *> _shapes;

public:
    App()
    {
    }
    ~App()
    {
    }

    // Inheritance -> 'Shape' replace [Circle, Triangle, Polygon]
    void add(Shape *input)
    {
        _shapes.push_back(input);
    }

    void sort()
    {
        std::sort(_shapes.begin(), _shapes.end(), compare);
    }

    // return pointer
    Shape *at(int i)
    {
        return _shapes.at(i);
    }
};

#endif