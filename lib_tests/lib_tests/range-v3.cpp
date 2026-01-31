#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <range/v3/all.hpp>

#include <string>
#include <vector>

TEST(RangeV3Test, Sort)
{
    auto v = std::vector{4, 5, 2, 3, 1};
    ranges::sort(v);
    EXPECT_EQ(v, (std::vector{1, 2, 3, 4, 5}));
}

TEST(RangeV3Test, Unique)
{
    auto v = std::vector{2, 1, 2, 3, 1};
    v |= ranges::actions::sort | ranges::actions::unique;
    EXPECT_EQ(v, (std::vector{1, 2, 3}));
}

TEST(RangeV3Test, Enumerate)
{
    auto v = std::vector<std::string>{"A", "B", "C"};

    auto v_expected = std::vector<std::pair<size_t, std::string>>{
        {0, "A"},
        {1, "B"},
        {2, "C"},
    };

    for (const auto& [index, value] : ranges::views::enumerate(v))
    {
        ASSERT_EQ(index, v_expected[index].first);
        ASSERT_EQ(value, v_expected[index].second);
    }
}

TEST(RangeV3Test, ComplexViews)
{
    const auto v = std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto v2 = v | ranges::views::remove_if([](int i) { return i % 2 == 1; })
              | ranges::views::transform([](int i) { return std::string{"i"} + std::to_string(i); })
              | ranges::to<std::vector>();
    EXPECT_EQ(v2, (std::vector<std::string>{"i2", "i4", "i6", "i8", "i10"}));
}
