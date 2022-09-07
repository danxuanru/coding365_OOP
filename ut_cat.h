#include <gtest/gtest.h>
#include "cat.h"

class CatTest : public ::testing::Test
{
protected:
    double DELTA = 0.01;
    Cat a, wrong;
    std::string name1;
    double weight1, weight2;
    void SetUp() override
    {
        name1 = "Cat01";
        weight1 = 3;
        weight2 = 6;
        a = Cat(name1, weight1);
        wrong = Cat(name1, weight2);
    }
};
TEST_F(CatTest, constructor)
{
    ASSERT_EQ(a.name(), name1);
    ASSERT_NEAR(a.weight(), weight1, DELTA);
    ASSERT_THROW(Cat("???", 10), std::range_error);
    ASSERT_THROW(Cat("???", 1), std::range_error);
}
TEST_F(CatTest, feed)
{
    a.feed();
    ASSERT_NEAR(3.2, a.weight(), DELTA);
    ASSERT_THROW(wrong.feed(), std::out_of_range);
}