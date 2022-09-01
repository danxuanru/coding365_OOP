#include <gtest/gtest.h>
#include "../src/school.h"
#include "../src/student.h"
#include "../src/teacher.h"

bool condition(SchoolMember *member)
{
    return member->id() < 100;
}

// test fixture
class SchoolTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        for (SchoolMember &member : school_members)
            ccu.addSchoolMember(&member);
    }

    School ccu;
    std::vector<SchoolMember> school_members =
        {
            Teacher(100, "Jassica"),
            Student(1, "Mike"),
            Teacher(101, "Bob"),
            Student(3, "Zack"),
            Student(13, "Josh", "Computer Science")};
    // const double DELTA = 0.001;
};

TEST_F(SchoolTest, addSchoolMember)
{
    std::vector<SchoolMember *> ans = ccu.getSchoolMemberWithCondition([](SchoolMember *member)
                                                                       { return member->id() > 0; });
    ASSERT_EQ(ans.at(0)->name(), "Jassica");
    ASSERT_EQ(ans.at(1)->name(), "Mike");
}

TEST_F(SchoolTest, getSchoolMemberWithCondition)
{

    std::vector<SchoolMember *> ans = ccu.getSchoolMemberWithCondition(condition);
    ASSERT_EQ(ans.size(), 3);
    ASSERT_EQ(ans.at(0)->id(), 1);
    ASSERT_EQ(ans.at(0)->name(), "Mike");
}