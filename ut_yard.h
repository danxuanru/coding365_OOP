#include <gtest/gtest.h>
#include "yard.h"
void extracMethod(Yard *y)
{
    y->addPet(new Cat("cat01", 3));
    y->addPet(new Dog("dog01", 20));
    y->addPet(new Cat("cat02", 4));
    y->addPet(new Dog("dog02", 30));
    y->addPet(new Cat("cat03", 5));
}
class YardTest : public ::testing::Test
{
protected:
    double DELTA = 0.01;
    void SetUp() override
    {
        ASSERT_EQ(Pet::amount(), 0);
        ASSERT_EQ(Cat::amount(), 0);
        ASSERT_EQ(Dog::amount(), 0);
    }
    void TearDown() override
    {
        ASSERT_EQ(Pet::amount(), 0);
        ASSERT_EQ(Cat::amount(), 0);
        ASSERT_EQ(Dog::amount(), 0);
    }
};
TEST_F(YardTest, lambda_function)
{
    Yard a;
    extracMethod(&a);
    std::vector<Pet *> ans = a.getPetWithCondition([](Pet *pet)
                                                   { return pet->weight() > 10; });
    ASSERT_EQ(2, ans.size());
    ASSERT_EQ(ans.at(0)->name(), "dog01");
    ASSERT_NEAR(ans.at(0)->weight(), 20, DELTA);
    ASSERT_EQ(ans.at(1)->name(), "dog02");
    ASSERT_NEAR(ans.at(1)->weight(), 30, DELTA);
}
bool func(Pet *pet)
{
    return pet->weight() < 10;
}
TEST_F(YardTest, pass_by_function)
{
    Yard a;
    extracMethod(&a);
    std::vector<Pet *> ans = a.getPetWithCondition(func);
    ASSERT_EQ(3, ans.size());
    ASSERT_EQ(ans.at(0)->name(), "cat01");
    ASSERT_NEAR(ans.at(0)->weight(), 3, DELTA);
    ASSERT_EQ(ans.at(1)->name(), "cat02");
    ASSERT_NEAR(ans.at(1)->weight(), 4, DELTA);
    ASSERT_EQ(ans.at(2)->name(), "cat03");
    ASSERT_NEAR(ans.at(2)->weight(), 5, DELTA);
}
class Functor
{
public:
    bool operator()(Pet *pet)
    {
        return pet->weight() > 10;
    }
};
TEST_F(YardTest, pass_by_functor)
{
    Yard a;
    extracMethod(&a);
    Functor test;
    std::vector<Pet *> ans = a.getPetWithCondition(test);
    ASSERT_EQ(2, ans.size());
    ASSERT_EQ(ans.at(0)->name(), "dog01");
    ASSERT_NEAR(ans.at(0)->weight(), 20, DELTA);
    ASSERT_EQ(ans.at(1)->name(), "dog02");
    ASSERT_NEAR(ans.at(1)->weight(), 30, DELTA);
}
TEST_F(YardTest, copy_assignment)
{
    Yard a;
    extracMethod(&a);
    Yard b = a;
    Functor test;
    std::vector<Pet *> ans = b.getPetWithCondition(test);
    ASSERT_EQ(2, ans.size());
    ASSERT_EQ(ans.at(0)->name(), "dog01");
    ASSERT_NEAR(ans.at(0)->weight(), 20, DELTA);
    ASSERT_EQ(ans.at(1)->name(), "dog02");
    ASSERT_NEAR(ans.at(1)->weight(), 30, DELTA);
}
TEST_F(YardTest, copy_constructor)
{
    Yard a;
    extracMethod(&a);
    Yard b(a);
    Functor test;
    std::vector<Pet *> ans = b.getPetWithCondition(test);
    ASSERT_EQ(2, ans.size());
    ASSERT_EQ(ans.at(0)->name(), "dog01");
    ASSERT_NEAR(ans.at(0)->weight(), 20, DELTA);
    ASSERT_EQ(ans.at(1)->name(), "dog02");
    ASSERT_NEAR(ans.at(1)->weight(), 30, DELTA);
}