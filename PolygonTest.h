#include <gtest/gtest.h>
#include "Polygon.h"

TEST(PolygonTest, Test01)
{
    double x[2] = {0, 0};
    double y[2] = {4, 0};
    double z[2] = {4, 4};
    double w[2] = {0, 4};
    MathVector arr[4] = {MathVector(2, x), MathVector(2, y), MathVector(2, z), MathVector(2, w)};
    Polygon p(arr);
    ASSERT_EQ(p.getName(), "shape::polygon");
}

TEST(PolygonTest, Test02)
{
    double x[2] = {0, 0};
    double y[2] = {4, 0};
    double z[2] = {4, 4};
    double w[2] = {0, 4};
    double t[2] = {2, 5};
    MathVector arr[5] = {MathVector(2, x), MathVector(2, y), MathVector(2, z), MathVector(2, w), MathVector(2, t)};
    Polygon p(arr);
    // ASSERT_EQ(p.area(), 16);
    ASSERT_NEAR(p.area(), 16, 0.01);
}
