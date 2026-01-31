#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <tabulate/table.hpp>

TEST(TabulateTest, Main)
{
    auto table = tabulate::Table{};

    table.add_row({"Col 1", "Col 2"});
    table.add_row({"AAA", "111"});
    table.add_row({"BBB", "222"});
    table.add_row({"CCC", "333"});

    EXPECT_EQ(table.str(), "+-------+-------+\n"
                           "| Col 1 | Col 2 |\n"
                           "+-------+-------+\n"
                           "| AAA   | 111   |\n"
                           "+-------+-------+\n"
                           "| BBB   | 222   |\n"
                           "+-------+-------+\n"
                           "| CCC   | 333   |\n"
                           "+-------+-------+");
}
