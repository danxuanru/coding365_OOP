#include <gtest/gtest.h>
#include "../src/student.h"

TEST(StudentTest, student)
{
    Student p(1, "Mike");
    ASSERT_EQ(p.id(), 1);
    ASSERT_EQ(p.name(), "Mike");
    ASSERT_EQ(p.department(), "Mechanical & Electrical Engineering");
    p.transfer("Computer Science");
    ASSERT_EQ(p.department(), "Computer Science");
}

TEST(StudentTest, addScore)
{
    Student p(1, "Mike");
    p.addScore(80);
    ASSERT_EQ(p.getScore(1), 80);
}

TEST(StudentTest, getScore)
{
    Student p(1, "Mike");
    p.addScore(80);
    p.addScore(95);
    p.addScore(90);
    ASSERT_EQ(p.getScore(1), 80);
    ASSERT_EQ(p.getScore(2), 95);
    ASSERT_EQ(p.getScore(3), 90);
    ASSERT_THROW(p.getScore(5), std::out_of_range);
    ASSERT_THROW(p.getScore(0), std::out_of_range);
}

TEST(StudentTest, scoreAverage) // fail
{
    Student p(1, "Mike");
    ASSERT_THROW(p.scoreAverage(), std::range_error);
    p.addScore(85);
    p.addScore(95);
    p.addScore(90);
    ASSERT_EQ(p.scoreAverage(), 90);
}
