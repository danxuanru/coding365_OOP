#include <gtest/gtest.h>
#include "Triangle.h"

TEST(TriangleTest, 01)
{
    double a[2] = {0, 0};
    double b[2] = {0, 3};
    double c[2] = {4, 0};
    MathVector x(2, a);
    MathVector y(2, b);
    MathVector z(2, c);
    Triangle t(x, y, z);
    t.perimeter();
    ASSERT_EQ(t.perimeter(), 12);
    ASSERT_EQ(t.area(), 6);
}
TEST(TriangleTest, 02)
{
    double a[2] = {4, 6};
    double b[2] = {9, 6};
    double c[2] = {4, 18};
    MathVector x(2, a);
    MathVector y(2, b);
    MathVector z(2, c);
    Triangle t(x, y, z);
    t.perimeter();
    ASSERT_EQ(t.perimeter(), 30);
    ASSERT_EQ(t.area(), 30);
}
TEST(TriangleTest, 03)
{
}