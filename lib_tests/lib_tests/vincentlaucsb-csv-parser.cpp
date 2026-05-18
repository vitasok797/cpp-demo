#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vincentlaucsb-csv-parser/csv.hpp>

#include <string>
#include <string_view>

static auto test_file(int header_row, const std::string& path, const char* expected_res) -> void
{
    auto format = csv::CSVFormat{};
    format.delimiter({';', ','});
    format.header_row(header_row);
    format.trim({' ', '\t'});

    auto csv = csv::CSVReader{path, format};

    if (header_row >= 0)
    {
        auto header_content = std::string{};
        for (const auto& col_header : csv.get_col_names())
        {
            header_content += "[";
            header_content += col_header;
            header_content += "]";
        }
        ASSERT_EQ(header_content, "[col1][col2]");
    }

    auto body_content = std::string{};
    for (const auto& row : csv)
    {
        auto is_single_empty_cell = (row.size() == 1 && row[0].is_null());
        if (is_single_empty_cell)
        {
            body_content += "*|";
            continue;
        }

        ASSERT_EQ(row.size(), 2);
        for (auto& cell : row)
        {
            body_content += "[";
            body_content += cell.get<std::string_view>();
            body_content += "]";
        }
        body_content += "|";
    }
    ASSERT_EQ(body_content, expected_res);
}

TEST(VincentlaucsbCsvParserTest, WithHeader)
{
    const auto data_dir = std::string{"lib_tests/data/csv"};
    const auto expected_res = "[val1][001]|[val2][002]|[val3][003]|";

    ASSERT_NO_FATAL_FAILURE(test_file(0, data_dir + "/data1_lf.csv", expected_res));
    ASSERT_NO_FATAL_FAILURE(test_file(0, data_dir + "/data2_crlf.csv", expected_res));
    ASSERT_NO_FATAL_FAILURE(test_file(0, data_dir + "/data3_utf8bom_lf.csv", expected_res));
}

TEST(VincentlaucsbCsvParserTest, WithoutHeader)
{
    const auto data_dir = std::string{"lib_tests/data/csv"};
    const auto expected_res = "[col1][col2]|[val1][001]|*|[val2][002]|[val3][003]|";

    ASSERT_NO_FATAL_FAILURE(test_file(-1, data_dir + "/data1_lf.csv", expected_res));
    ASSERT_NO_FATAL_FAILURE(test_file(-1, data_dir + "/data2_crlf.csv", expected_res));
    ASSERT_NO_FATAL_FAILURE(test_file(-1, data_dir + "/data3_utf8bom_lf.csv", expected_res));
}
