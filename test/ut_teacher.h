#include <gtest/gtest.h>
#include "../src/teacher.h"

class TeacherTest : public ::testing::Test
{
};

TEST(TeacherTest, teacher)
{
    Teacher p(100, "Jassica");
    ASSERT_EQ(p.id(), 100);
    ASSERT_EQ(p.name(), "Jassica");
    ASSERT_EQ(p.department(), "Mechanical & Electrical Engineering");
    p.transfer("Computer Science");
    ASSERT_EQ(p.department(), "Computer Science");
}
TEST(TeacherTest, addStudent)
{
    Student m(3, "Zack");
    Student n(4, "Jake");
    Student q(13, "Josh", "Computer Science");
    Teacher p(100, "Jassica");
    p.addStudent(m);
    p.addStudent(n);
    ASSERT_EQ(p.getStudentById(3).name(), "Zack");
    ASSERT_EQ(p.getStudentById(4).name(), "Jake");
    ASSERT_THROW(p.addStudent(q), std::domain_error);
}

TEST(TeacherTest, getStudentById)
{
    Student m(3, "Zack");
    Student n(4, "Jake");
    Teacher p(100, "Jassica");
    p.addStudent(m);
    p.addStudent(n);
    ASSERT_EQ(p.getStudentById(3).name(), "Zack");
    ASSERT_EQ(p.getStudentById(4).name(), "Jake");
    ASSERT_THROW(p.getStudentById(99), std::range_error);
}