#ifndef SCHOOL_H
#define SCHOOL_H

#include <vector>

#include "school_member.h"

class School
{
public:
  School() = default;

  // School(SchoolMember *const member)
  // {
  //   _schoolMember.push_back(member);
  // }

  // destructor (empty)
  ~School()
  {
    // for (int i = 0; i < _schoolMember.size(); i++)
    //   delete _schoolMember.at(i);
  }

  void addSchoolMember(SchoolMember *const member)
  {
    _schoolMember.push_back(member);
  }

  template <typename Condition>
  std::vector<SchoolMember *> getSchoolMemberWithCondition(Condition cond)
  {
    std::vector<SchoolMember *> school_member_in_cond;
    for (SchoolMember *member : _schoolMember)
    {
      if (cond(member) == true)
        school_member_in_cond.push_back(member);
    }
    return school_member_in_cond;
  }

private:
  std::vector<SchoolMember *> _schoolMember;

  // copy asssignment
  School &operator=(School const &other) { return *this; }
  // copy constructor
  School(School const &other) {}

  // void deep_copy(std::vector<SchoolMember *> member)
  // {
  //   for (int i = 0; i < member.size(); i++)
  //   {
  //   }
  // }
};

#endif
