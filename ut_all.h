#include <gtest/gtest.h>
#include <iostream>
using namespace std;
#include "helloworld.h"

TEST(HELLOWORLD, PrintHelloWorld) // GroupName, TestName
{
    string output = PrintHelloWorld();
    string compare = "Hello World! \n";
    ASSERT_EQ(output, compare); // ASSERT_EQ: expected==actual
}
TEST(HELLOWORLD, testname)
{
    string name = "Taiwan";
    string output = HelloWorld(name);
    string compare = "Hello World, Taiwan!";
    ASSERT_EQ(output, compare); // ASSERT_EQ: expected==actual
}