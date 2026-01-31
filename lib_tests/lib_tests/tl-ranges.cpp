#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <tl/enumerate.hpp>
#include <tl/to.hpp>

#include <ranges>
#include <vector>

TEST(TlRangesTest, Main)
{
    auto vec = std::vector{1, 2, 3, 4, 5};

    auto vec_res = vec                                                     //
                   | std::views::reverse                                   //
                   | std::views::take(3)                                   //
                   | std::views::transform([](auto i) { return i * 10; })  //
                   | tl::views::enumerate                                  //
                   | tl::to<std::vector>();                                //

    auto vec_expected = std::vector<std::pair<size_t, int>>{
        {0, 50},
        {1, 40},
        {2, 30},
    };

    ASSERT_EQ(vec_res, vec_expected);
}
