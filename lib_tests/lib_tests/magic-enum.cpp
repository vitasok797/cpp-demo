#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <magic_enum/magic_enum.hpp>

enum class Color
{
    none,
    red,
    blue,
    green
};

TEST(MagicEnumTest, ToString)
{
    auto color = Color::red;
    EXPECT_EQ(magic_enum::enum_name(color), "red");
}

TEST(MagicEnumTest, FromString)
{
    auto text = "grEEn";
    auto color = magic_enum::enum_cast<Color>(text, magic_enum::case_insensitive);
    ASSERT_TRUE(color.has_value());
    EXPECT_EQ(color.value(), Color::green);
}

TEST(MagicEnumTest, FromStringWithDefault)
{
    auto text = "xxx";
    auto color = magic_enum::enum_cast<Color>(text).value_or(Color::none);
    EXPECT_EQ(color, Color::none);
}

TEST(MagicEnumTest, FromInt)
{
    auto color = magic_enum::enum_cast<Color>(2).value_or(Color::none);
    EXPECT_EQ(color, Color::blue);
}

TEST(MagicEnumTest, EnumElementsCount)
{
    auto color_count = magic_enum::enum_count<Color>();
    EXPECT_EQ(color_count, 4);
}

TEST(MagicEnumTest, EnumContains)
{
    EXPECT_TRUE(magic_enum::enum_contains<Color>(2));
    EXPECT_TRUE(magic_enum::enum_contains<Color>("green"));
    EXPECT_FALSE(magic_enum::enum_contains<Color>(123));
    EXPECT_FALSE(magic_enum::enum_contains<Color>("black"));
}
