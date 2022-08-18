#include <gtest/gtest.h>
using namespace std;
#include "Dog.h"

TEST(ToyTest, getName)
{
    Toy a("toy1");
    ASSERT_EQ(a.getName(), "toy1");
}
TEST(DogTest, Dog1) // constructor
{
    Dog a("dog1", 20);
    ASSERT_EQ(a.getName(), "dog1");
}
TEST(DogTest, Dog2) // copy constructor
{
    Dog m("dog2", 50);
    Dog n = m;
    ASSERT_EQ(n.getName(), "dog2");
    ASSERT_EQ(n.getWeight(), 50);
}
TEST(DogTest, Dog3) // copy assignment
{
    Dog m("dog3", 45);
    Dog n;
    n = m;
    ASSERT_EQ(n.getName(), "dog3");
    ASSERT_EQ(n.getWeight(), 45);
}
TEST(DogTest, addNewToy)
{
    Dog a("dog1", 20);
    Toy m("toy1");
    Toy n("toy2");
    a.addNewToy(m);
    a.addNewToy(n);
    // a.collection();
    ASSERT_EQ(a.getToy(0).getName(), "toy1");
    ASSERT_EQ(a.getToy(1).getName(), "toy2");
}
TEST(DogTest, getToy)
{
    Dog a("dog1", 30);
    Toy m("doll");
    Toy n("robot");
    Toy q("ball");
    a.addNewToy(m);
    a.addNewToy(n);
    a.addNewToy(q);
    ASSERT_EQ(a.getToy(0).getName(), "doll");
    ASSERT_EQ(a.getToy(1).getName(), "robot");
    ASSERT_EQ(a.getToy(2).getName(), "ball");
}
TEST(DogTest, isHeavierThan)
{
    Dog a("dog1", 20);
    Dog b("dog2", 50);
    ASSERT_EQ(a.isHeavierThan(b), false);
    ASSERT_EQ(b.isHeavierThan(a), true);
}