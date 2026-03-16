#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <./rapidcsv.h>

#include <sstream>
#include <string>
#include <vector>

TEST(RapidCsvTest, ParseFromString)
{
    auto csv_data = std::string{"Name,Age,Score\n"
                                "Alice,25,95.5\n"
                                "Bob,30,88.0"};
    auto ss = std::stringstream{csv_data};
    auto doc = rapidcsv::Document{ss};
    auto ages = doc.GetColumn<int>("Age");

    ASSERT_EQ(ages.size(), 2);
    EXPECT_EQ(ages[0], 25);
    EXPECT_EQ(ages[1], 30);
}
