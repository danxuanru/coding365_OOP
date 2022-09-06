#include <gtest/gtest.h> // Google Test (Unit Test)
#include <iostream>
using namespace std;
//#include "ut_all.h"
//#include "MathVectorTest.h"
#include "TriangleTest.h"
#include "CircleTest.h"
#include "PolygonTest.h"
#include "AppTest.h"
//#include "DogTest.h"

int main(int argc, char **argv)
{
    testing ::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}