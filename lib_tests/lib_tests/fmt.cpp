#include <fmt/format.h>
#include <fmt/ranges.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vector>

TEST(FmtTest, Format)
{
    auto s1 = fmt::format("The answer is {}", 42);
    EXPECT_EQ(s1, "The answer is 42");

    auto s2 = fmt::format("I'd rather be {1} than {0}", "right", "happy");
    EXPECT_EQ(s2, "I'd rather be happy than right");
}

TEST(FmtTest, FormatVector)
{
    auto v = std::vector<int>{1, 2, 3};
    EXPECT_EQ(fmt::format("{}", v), "[1, 2, 3]");
}

TEST(FmtTest, ToString)
{
    EXPECT_EQ(fmt::to_string(333), "333");
}
