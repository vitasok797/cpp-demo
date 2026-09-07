#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <stdexcept>
#include <string>

namespace integration_tests
{

using ::testing::HasSubstr;

TEST(GtestDemoTest, AssertThrow)
{
    auto do_throw = []() { throw std::runtime_error{""}; };
    ASSERT_THROW(do_throw(), std::runtime_error);
}

TEST(GtestDemoTest, AssertThat)
{
    auto s = std::string{"123xxx456"};
    ASSERT_THAT(s, HasSubstr("xxx")) << "String \"" << s << "\" does not contain \"xxx\"";
}

TEST(GtestDemoTest, Fail)
{
    auto s = std::string{"123"};
    if (s.empty()) FAIL() << "s is empty";
}

TEST(GtestDemoTest, Propagating)
{
    auto test_failure = false;
    auto sub = [=]() { ASSERT_FALSE(test_failure); };

    // sub();
    ASSERT_NO_FATAL_FAILURE(sub());

    ASSERT_FALSE(test_failure) << "nooooooooooo";
}

}  // namespace integration_tests
