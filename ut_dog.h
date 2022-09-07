#include <gtest/gtest.h>
#include "dog.h"

TEST(DogTest, constructor)
{
    Dog m("Jake", 20);
    ASSERT_EQ(m.name(), "Jake");
    ASSERT_EQ(m.weight(), 20);
    ASSERT_THROW(Dog("Mike", 9), std::range_error);
}
TEST(DogTest, feed)
{
    Dog m("Jake", 49);
    m.feed();
    ASSERT_EQ(m.weight(), 49.8);
    ASSERT_THROW(m.feed(), std::out_of_range);
}
