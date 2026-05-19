#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <vincentlaucsb-csv-parser/csv.hpp>

#include <stdexcept>
#include <string>

using namespace testing;

static auto get_default_format() -> auto
{
    auto format = csv::CSVFormat{};
    format.delimiter({';', ','});
    format.trim({' ', '\t'});
    return format;
}

static auto process_file(const auto& format, const std::string& path) -> std::string
{
    auto csv = csv::CSVReader{path, format};

    auto content = std::string{};

    for (const auto& col_header : csv.get_col_names())
    {
        content += "(";
        content += col_header;
        content += ")";
    }

    content += " H ";

    for (const auto& row : csv)
    {
        if (row.empty())
        {
            content += "empty row | ";
            continue;
        }

        auto is_single_empty_cell = (row.size() == 1 && row[0].is_null());
        if (is_single_empty_cell)
        {
            content += "empty cell | ";
            continue;
        }

        for (auto& cell : row)
        {
            content += "[";
            content += cell.get_sv();
            content += "]";
        }
        content += " | ";
    }

    return content;
}

static auto test_files(const auto& format, const char* expected_res) -> void
{
    const auto data_dir = std::string{"lib_tests/data/csv"};
    ASSERT_EQ(process_file(format, data_dir + "/data1_lf.csv"), expected_res);
    ASSERT_EQ(process_file(format, data_dir + "/data2_crlf.csv"), expected_res);
    ASSERT_EQ(process_file(format, data_dir + "/data3_utf8bom_lf.csv"), expected_res);
}

TEST(VincentlaucsbCsvParserTest, WithHeader)
{
    auto format = get_default_format();
    format.header_row(0);

    const auto expected_res = "(col1)(col2) H [val1][001] | [val2][002] | [val5][005] | ";

    ASSERT_NO_FATAL_FAILURE(test_files(format, expected_res));
}

TEST(VincentlaucsbCsvParserTest, NoHeader)
{
    auto format = get_default_format();
    format.no_header();
    // format.variable_columns(csv::VariableColumnPolicy::KEEP);  // default

    const auto expected_res = " H [col1][col2] | [val1][001] | empty cell | [val2][002] | empty row | [val3] | "
                              "[val4][004][xxx] | [val5][005] | ";

    ASSERT_NO_FATAL_FAILURE(test_files(format, expected_res));
}

TEST(VincentlaucsbCsvParserTest, NoHeaderKeepNonEmpty)
{
    auto format = get_default_format();
    format.no_header();
    format.variable_columns(csv::VariableColumnPolicy::KEEP_NON_EMPTY);

    const auto expected_res =
        " H [col1][col2] | [val1][001] | empty cell | [val2][002] | [val3] | [val4][004][xxx] | [val5][005] | ";

    ASSERT_NO_FATAL_FAILURE(test_files(format, expected_res));
}

TEST(VincentlaucsbCsvParserTest, NoHeaderIgnoreRow)
{
    auto format = get_default_format();
    format.no_header();
    format.variable_columns(csv::VariableColumnPolicy::IGNORE_ROW);

    const auto expected_res = " H [col1][col2] | [val1][001] | [val2][002] | [val5][005] | ";

    ASSERT_NO_FATAL_FAILURE(test_files(format, expected_res));
}

TEST(VincentlaucsbCsvParserTest, NoHeaderThrow)
{
    auto format = get_default_format();
    format.no_header();
    format.variable_columns(csv::VariableColumnPolicy::THROW);

    // "Line too short" or "Line too long"
    ASSERT_THAT([&] { test_files(format, ""); }, ThrowsMessage<std::runtime_error>(HasSubstr("Line too short")));
}
