#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <gsl/narrow>
#include <gsl/util>

TEST(GslTest, NarrowCast)
{
    auto a = size_t{1};
    auto b = gsl::narrow_cast<int>(a);
    EXPECT_EQ(b, 1);
}

TEST(GslTest, NarrowingError)
{
    EXPECT_THROW(
        {
            auto a = int{-1};
            [[maybe_unused]] auto b = gsl::narrow<size_t>(a);
        },
        gsl::narrowing_error);
}
