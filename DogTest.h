#include <gtest/gtest.h>
using namespace std;
#include "Dog.h"

TEST(DogTest, getName)
{
    Dog a("dog1", 20);
    ASSERT_EQ(a.getName(), "dog1");
}
TEST(DogTest, getWeight)
{
    Dog a("dog1", 20);
    ASSERT_EQ(a.getWeight(), 20);
}
TEST(DogTest, addNewToy)
{
    Dog a("dog1", 20);
    a.addNewToy("toy1");
    a.addNewToy("toy2");
    ASSERT_EQ(a.getToy(0), "toy1");
    ASSERT_EQ(a.getToy(1), "toy2");
}
TEST(DogTest, getToy)
{
    Dog a("dog1", 20);
    a.addNewToy("toy1");
    a.addNewToy("toy2");
    ASSERT_EQ(a.getToy(0), "toy1");
    ASSERT_EQ(a.getToy(1), "toy2");
}