#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vincentlaucsb-csv-parser/csv.hpp>

#include <string>
#include <string_view>

static auto test_file(const std::string& path) -> void
{
    auto format = csv::CSVFormat{};
    format.delimiter({';', ','});
    format.header_row(0);
    format.trim({' ', '\t'});

    auto csv = csv::CSVReader{path, format};

    auto header_content = std::string{};
    for (const auto& col_header : csv.get_col_names())
    {
        header_content += "[";
        header_content += col_header;
        header_content += "]";
    }
    ASSERT_EQ(header_content, "[col1][col2]");

    auto body_content = std::string{};
    for (const auto& row : csv)
    {
        ASSERT_EQ(row.size(), 2);
        for (auto& cell : row)
        {
            body_content += "[";
            body_content += cell.get<std::string_view>();
            body_content += "]";
        }
        body_content += "|";
    }
    ASSERT_EQ(body_content, "[val1][001]|[val2][002]|[val3][003]|");
}

TEST(VincentlaucsbCsvParserTest, Complex)
{
    const auto data_dir = std::string{"lib_tests/data/csv"};

    ASSERT_NO_FATAL_FAILURE(test_file(data_dir + "/data1_lf.csv"));
    ASSERT_NO_FATAL_FAILURE(test_file(data_dir + "/data2_crlf.csv"));
    ASSERT_NO_FATAL_FAILURE(test_file(data_dir + "/data3_utf8bom_lf.csv"));
}
