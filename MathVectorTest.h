#include <gtest/gtest.h>
#include "MathVector.h"
using namespace std;

TEST(MathVector, Test01)
{
    int d = 2;
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
    MathVector n = m; // copy constructor
    MathVector z;
    for (int i = 0; i < 10; i++)
    {
        z = m;
    }
    ASSERT_EQ(z.getDim(), 2);
    ASSERT_EQ(n.getDim(), 2);
}
TEST(MathVector, Test07)
{
    double y[2] = {3, 4};
    MathVector m(2, y);
    double x[2] = {5, 6};
    MathVector n(2, x);
    // We want to add m to n
    n.add(m); // copy constructor
    ASSERT_EQ(n.getDim(), 2);
    ASSERT_EQ(n.getAt(0), 8);
    ASSERT_EQ(n.getAt(1), 10);
}
TEST(MathVector, Test08)
{
    double y[2] = {3, 4};
    MathVector m(2, y);
    double x[2] = {5, 6};
    MathVector n(2, x);
    MathVector r, u;
    r = m + n; // m.+(n)
    u = m - n; // m.-(n)
    ASSERT_EQ(r.getDim(), 2);
    ASSERT_EQ(u.getDim(), 2);
    // ASSERT_EQ(r.getAt(0), 8);
    // ASSERT_EQ(r.getAt(1), 10);
    // ASSERT_EQ(u.getAt(0), -2);
    // ASSERT_EQ(u.getAt(1), -2);
    // r = u = m = n;
    cout << r.getAt(0) << endl;
    cout << r.getAt(1) << endl;
    // cout << u.getAt(0) << endl;
    // cout << m.getAt(0) << endl;
    // cout << n.getAt(0) << endl;
}
TEST(MathVector, Test09)
{
    double y[2] = {3, 4};
    MathVector m(2, y);
    double q = 10;
    ASSERT_EQ(m.getDim(), 2);
    m = q;
    ASSERT_EQ(m.getDim(), 10);
}
TEST(MathVector, Test10)
{
    double y[2] = {3, 4};
    MathVector m(2, y);
    double e = 5;
    ASSERT_EQ(m.getDim(), 2);
    m.expand(e);
    ASSERT_EQ(m.getDim(), 3);
    ASSERT_EQ(m.getAt(0), 3);
    ASSERT_EQ(m.getAt(1), 4);
    ASSERT_EQ(m.getAt(2), 5);
}
