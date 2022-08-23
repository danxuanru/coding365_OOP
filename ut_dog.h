#include <gtest/gtest.h>
#include "dog.h"

TEST(DogTest, constructor)
{
    Dog m("Jake", 20);
    ASSERT_EQ(m.getName(), "Jake");
    ASSERT_EQ(m.getWeight(), 20);
    ASSERT_THROW(Dog("Mike", 9), std::range_error);
}
TEST(DogTest, feed)
{
    Dog m("Jake", 49);
    m.feed();
    ASSERT_EQ(m.getWeight(), 49.8);
    ASSERT_THROW(m.feed(), std::out_of_range);
}
