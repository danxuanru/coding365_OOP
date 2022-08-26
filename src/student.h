#ifndef STUDENT_H
#define STUDENT_H

#include <numeric>   // std::accumulate
#include <stdexcept> // std::out_of_range, std::range_error
#include <string>
#include <vector>

#include "school_member.h"

class Student : public SchoolMember
{
public:
  Student(int const id, std::string const &name, std::string const &department = "Mechanical & Electrical Engineering") : SchoolMember(id, name, department)
  {
    _scores.push_back(0);
  }
  // ~Student()
  // {
  // }

  void addScore(double const score)
  {
    _scores.push_back(score);
  }

  double getScore(int const number_of_test) const
  {
    if (number_of_test == 0 || _scores.size() <= number_of_test)
      throw std::out_of_range("ERROR: NO_SUCH_NUMBER_OF_TEST");
    return _scores.at(number_of_test);
  }

  double scoreAverage() const
  {
    if (_scores.size() == 1)
      throw std::range_error("ERROR:NO_SCORE");

    double sum = 0;
    // index from 1
    for (int i = 1; i < _scores.size(); i++)
      sum += _scores.at(i);
    double ans = sum / (_scores.size() - 1);
    return ans;
  }

private:
  // store student's hw scores
  std::vector<double> _scores;
};

#endif
