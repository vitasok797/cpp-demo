#include "to_str.h"

#include <gtest/gtest.h>

namespace to_str::test
{

TEST(ToStrTest, IntToStr)
{
    ASSERT_EQ(int_to_str(123), "123");
}

}  // namespace to_str::test
