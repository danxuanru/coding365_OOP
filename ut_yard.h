#include <gtest/gtest.h>
#include "yard.h"
#include "pet.h"
#include "cat.h"
#include "dog.h"

bool condition(Pet *pet)
{
    if (pet->weight() > 20)
        return true;
    else
        return false;
}

void extraMethod(Yard *yard)
{
    yard->addPet(new Cat("cat01", 2));
    yard->addPet(new Dog("dog01", 30));
    yard->addPet(new Cat("cat02", 3));
    yard->addPet(new Dog("dog02", 50));
    yard->addPet(new Cat("cat03", 2));
}

class YardTest : public ::testing ::Test
{
protected:
    // Yard y;

    // SetUp() & TearDown() run every test case
    void SetUp() override
    {
        ASSERT_EQ(Pet::amount(), 0);
        ASSERT_EQ(Cat::amount(), 0);
        ASSERT_EQ(Dog::amount(), 0);
        // extraMethod(&y);
        // std::cout << "SetUp is called\n";
    }
    void TearDown() override
    {
        ASSERT_EQ(Pet::amount(), 0);
        ASSERT_EQ(Cat::amount(), 0);
        ASSERT_EQ(Dog::amount(), 0);
        // std::cout << "TearDown is called\n";
    }
};

class Fun
{
public:
    bool operator()(Pet *p)
    {
        return p->weight() < 20;
    }
};

TEST_F(YardTest, Test01)
{
    Yard y;
    extraMethod(&y);
    std::vector<Pet *> ans;
    ans = y.getPetWithCondition(condition); // condition -> comp (in template)
    ASSERT_EQ(ans.size(), 2);
    ASSERT_EQ(Pet::amount(), 5);
    ASSERT_EQ(Cat::amount(), 3);
    ASSERT_EQ(Dog::amount(), 2);
}
TEST_F(YardTest, Test02)
{
    Yard y;
    extraMethod(&y);
    std::vector<Pet *> ans;
    // lambda function []
    ans = y.getPetWithCondition([](Pet *p)
                                { return p->weight() > 0; });
    ASSERT_EQ(ans.size(), 5);
}
TEST_F(YardTest, Test03)
{
    Yard y;
    extraMethod(&y);
    std::vector<Pet *> ans;
    // class object as function
    Fun f;
    ans = y.getPetWithCondition(f);
    ASSERT_EQ(ans.size(), 3);
}