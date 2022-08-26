#include <gtest/gtest.h>
#include "../src/school.h"
#include "../src/student.h"
#include "../src/teacher.h"

bool condition(SchoolMember *member)
{
    return member->id() < 100;
}

void extraMethod(School *school)
{
    school->addSchoolMember(new Teacher(100, "Jassica"));
    school->addSchoolMember(new Student(1, "Mike"));
    school->addSchoolMember(new Teacher(101, "Bob"));
    school->addSchoolMember(new Student(3, "Zack"));
    school->addSchoolMember(new Student(13, "Josh", "Computer Science"));
}

TEST(SchoolTest, addSchoolMember)
{
    School s(new Teacher(100, "Jassica"));
    Student m(1, "Mike");
    s.addSchoolMember(new SchoolMember(m));
    std::vector<SchoolMember *> ans = s.getSchoolMemberWithCondition([](SchoolMember *member)
                                                                     { return member->id() > 0; });
    ASSERT_EQ(ans.at(0)->name(), "Jassica");
    ASSERT_EQ(ans.at(1)->name(), "Mike");
}

TEST(SchoolTest, getSchoolMemberWithCondition)
{
    School s;
    extraMethod(&s);
    std::vector<SchoolMember *> ans = s.getSchoolMemberWithCondition(condition);
    ASSERT_EQ(ans.size(), 3);
    ASSERT_EQ(ans.at(0)->id(), 1);
    ASSERT_EQ(ans.at(0)->name(), "Mike");
}