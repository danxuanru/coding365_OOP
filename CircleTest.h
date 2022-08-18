#include <gtest/gtest.h>
#include "Circle.h"
#include "Triangle.h"

TEST(CircleTest, Test01)
{
    double arr[2] = {3, 4};
    double r = 0;
    // ASSERT_THROW(Circle(arr, r), std::string);
}
TEST(CircleTest, Test02)
{
    double arr[2] = {3, 4};
    double r = 5;
    Circle c(arr, r);
    ASSERT_NEAR(c.perimeter(), 10 * M_PI, 0.01);
    // ASSERT_EQ(c.perimeter(), 10 * M_PI);
}
TEST(CircleTest, Test03)
{
    double arr[2] = {3, 4};
    double r = 5;
    Circle c(arr, r);
    ASSERT_NEAR(c.area(), 25 * M_PI, 0.01);
}
TEST(CircleTest, Test04)
{
    double arr[2] = {3, 4};
    double r = 5;
    // use Basic class's pointer to contain Derived class' object
    Shape *s = new Circle(arr, r);
    s->getName();
    ASSERT_EQ(s->getName(), "shape::circle");

    // Shape *s2 = new Triangle();
    // // Shape s3(); -> it will be a Shape's object and couldn't change
    // std::vector<Shape *> v;
    // v.push_back(new Circle(arr, r));
    // v.push_back(new Triangle());
    // // use same function(interface) to call every class has in common
    // for (int i = 0; i < v.size(); i++)
    // {
    //     v.at(i)->perimeter();
    // }
}