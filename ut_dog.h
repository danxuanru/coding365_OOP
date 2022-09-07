#include <gtest/gtest.h>
#include "dog.h"

class DogTest : public ::testing::Test
{
protected:
    double DELTA = 0.01;
    double weight1, weight2;
    std::string name1;
    Dog a, wrong;
    void SetUp() override
    {
        name1 = "Dog01";
        weight1 = 20;
        weight2 = 50;
        a = Dog(name1, weight1);
        wrong = Dog(name1, weight2);
    }
};
TEST_F(DogTest, constructor)
{
    ASSERT_EQ(a.name(), name1);
    ASSERT_NEAR(a.weight(), weight1, DELTA);
    ASSERT_THROW(Dog(name1, 60), std::range_error);
    ASSERT_THROW(Dog(name1, 9), std::range_error);
}
TEST_F(DogTest, feed)
{
    a.feed();
    ASSERT_NEAR(a.weight(), 20.8, DELTA);
    ASSERT_THROW(wrong.feed(), std::out_of_range);
}
