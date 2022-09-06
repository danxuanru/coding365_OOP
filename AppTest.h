#include <gtest/gtest.h>
#include "Circle.h"
#include "Triangle.h"
#include "Polygon.h"
#include "Shape.h"
#include "App.h"

class AppTest_F : public ::testing::Test
{
protected:
    double arr1[2] = {3, 4};
    double r = 5;
    Circle c;
    double x[2] = {0, 0};
    double y[2] = {4, 0};
    double z[2] = {4, 4};
    double w[2] = {0, 4};
    MathVector arr2[4] = {MathVector(2, x), MathVector(2, y), MathVector(2, z), MathVector(2, w)};
    Polygon p;
    void SetUp() override
    {
        c = Circle(arr1, r);  // area = 25*3.14
        p = Polygon(arr2, 4); // area = 16
    }
};

TEST_F(AppTest_F, Test01)
{
    App a;
    a.add(&c); // & pointer : get address
    a.add(&p);
    a.sort();
    ASSERT_NEAR(a.at(0)->area(), 16, 0.01);
    ASSERT_NEAR(a.at(1)->area(), 78.537, 0.01);
}
