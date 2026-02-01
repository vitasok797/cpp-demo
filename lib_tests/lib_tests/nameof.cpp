#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <./nameof.hpp>

struct TestStruct
{
    int field{};
};

TEST(NameofTest, NameOf)
{
    auto i = 1;
    EXPECT_EQ(NAMEOF(i), "i");

    auto s = TestStruct{};
    EXPECT_EQ(NAMEOF(s.field), "field");
}

TEST(NameofTest, NameOfType)
{
    EXPECT_EQ(NAMEOF_SHORT_TYPE(TestStruct), "TestStruct");
}
