#include <gtest/gtest.h>
#include <iostream>
using namespace std;

#include "ut_cat.h"
#include "ut_dog.h"
#include "ut_yard.h"

int main(int argc, char **argv)
{
    testing ::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}