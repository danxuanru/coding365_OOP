#include <gtest/gtest.h>
#include "cat.h"

TEST(CatTest, constructor)
{
    Cat m("Kitty", 4);
    ASSERT_EQ(m.name(), "Kitty");
    ASSERT_EQ(m.weight(), 4);
    ASSERT_THROW(Cat("Cherry", 8), std::range_error);
}
TEST(CatTest, feed)
{
    Cat m("Kitty", 5.7);
    m.feed();
    ASSERT_EQ(m.weight(), 5.9);
    ASSERT_THROW(m.feed(), std::out_of_range);
}
