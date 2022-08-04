#include <gtest/gtest.h>
#include "MathVector.h"

TEST(MathVector, Test01)
{
    int d=2;
    double w[2] = {5, 6};  
    // MathVector n;  call to default constructor
    MathVector m(d, w);
    ASSERT_EQ(m.getDim(), d);
}
TEST(MathVector, Test02)
{
    int d = 2;
    double w[2] = {5, 6};
    MathVector m(d, w);
    ASSERT_EQ(m.getAt(0), w[0]);
    ASSERT_EQ(m.getAt(1), w[1]);
}
TEST(MathVector, Test03)
{
    int d = 3;
    double w[3] = {5, 6, 7};
    MathVector m(d, w);
    ASSERT_EQ(m.getAt(0), w[0]);
    ASSERT_EQ(m.getAt(1), w[1]);
    ASSERT_EQ(m.getAt(2), w[2]);
}

TEST(MathVector, Test04)
{
    int d = 2;
    double w[2] = {3, 4};
    MathVector m(d, w);
    ASSERT_EQ(m.length(), 5);
}
TEST(MathVector, Test05)
{
    int d = 2;
    MathVector m;
    m.setDim(d);
    ASSERT_EQ(m.getDim(), d);
}
TEST(MathVector, Test06)
{
    // int i = 10;
    // int j = i;
    // int d;
    // d = i;
    // string s = "123";
    // string q = s;
    // string w;
    // w = s;
    double y[2] = {3, 4};
    MathVector m(2, y);
    MathVector n = m;
    MathVector z;
    z = m;
    ASSERT_EQ(z.getDim(), 2);
    ASSERT_EQ(n.getDim(), 2);
}