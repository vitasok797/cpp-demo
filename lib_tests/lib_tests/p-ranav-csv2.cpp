#include <csv2/reader.hpp>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <string>

auto test_file(const std::string& path) -> void
{
    auto csv = csv2::Reader<                                 //
        csv2::delimiter<';'>,                                //
        csv2::quote_character<'"'>,                          //
        csv2::first_row_is_header<true>,                     //
        csv2::trim_policy::trim_characters<' ', '\t', '\r'>  //
        >{};                                                 //

    ASSERT_TRUE(csv.mmap(path));

    ASSERT_EQ(csv.rows(), 6);
    ASSERT_EQ(csv.cols(), 2);

    auto header_content = std::string{};
    const auto header = csv.header();
    for (const auto& header_item : header)
    {
        auto value = std::string{};
        header_item.read_value(value);
        if (!value.empty())
        {
            header_content += "[" + value + "]";
        }
    }
    ASSERT_EQ(header_content, "[col1][col2]");

    auto body_content = std::string{};
    for (const auto& row : csv)
    {
        for (const auto& cell : row)
        {
            auto value = std::string{};
            cell.read_value(value);
            if (!value.empty())
            {
                body_content += "[" + value + "]";
            }
        }
        body_content += "|";
    }
    ASSERT_EQ(body_content, "[val1][001]||[val2][002]||[val3][003]||");
}

TEST(PRanavCsv2Test, Complex)
{
    // auto data_dir = std::string{"../../../lib_tests/data/p-ranav-csv2"};
    auto data_dir = std::string{"lib_tests/data/p-ranav-csv2"};

    ASSERT_NO_FATAL_FAILURE(test_file(data_dir + "/test1_lf.csv"));
    ASSERT_NO_FATAL_FAILURE(test_file(data_dir + "/test2_crlf.csv"));
}
