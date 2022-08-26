#include <gtest/gtest.h>
#include "../test/ut_school.h"
#include "../test/ut_student.h"
#include "../test/ut_teacher.h"

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
