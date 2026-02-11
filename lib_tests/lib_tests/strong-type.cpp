#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <strong_type/strong_type.hpp>

using MyInt = strong::type<int, struct MyInt_tag>;
using MyInt2 = strong::type<int, struct MyInt2_tag, strong::regular, strong::ordered>;

static auto check_my_int(const MyInt& value, int raw_value) -> void
{
    EXPECT_EQ(value_of(value), raw_value);
    EXPECT_EQ(value.value_of(), raw_value);
}

TEST(StrongTypeTest, FunctionArgument)
{
    ASSERT_NO_FATAL_FAILURE(check_my_int(MyInt{42}, 42));

    // compile errors
    // check_my_int(MyInt2{42}, 42);
    // check_my_int(42, 42);
}

TEST(StrongTypeTest, Equality)
{
    EXPECT_EQ(MyInt2{42}, MyInt2{42});
    EXPECT_NE(MyInt2{42}, MyInt2{1});
    EXPECT_TRUE(MyInt2{42} > MyInt2{1});
}
