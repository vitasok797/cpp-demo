#include <csv2/reader.hpp>

#include <iostream>

auto test_file(const std::string& path) -> void
{
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "File: " << path << std::endl;
    std::cout << "----------------------------------------------" << std::endl;

    auto csv = csv2::Reader<              //
        csv2::delimiter<';'>,             //
        csv2::quote_character<'"'>,       //
        csv2::first_row_is_header<true>,  //
        // csv2::trim_policy::trim_whitespace
        csv2::trim_policy::trim_characters<' ', '\t', '\r'>  //
        >{};                                                 //

    if (!csv.mmap(path)) return;

    std::cout << "Rows: " << csv.rows() << std::endl;
    std::cout << "Cols: " << csv.cols() << std::endl;
    std::cout << std::endl;

    const auto header = csv.header();
    std::cout << "Header:" << std::endl;
    for (const auto& header_item : header)
    {
        auto value = std::string{};
        header_item.read_value(value);
        std::cout << "[" << value << "]" << std::endl;
    }
    std::cout << std::endl;

    for (const auto& row : csv)
    {
        for (const auto& cell : row)
        {
            auto value = std::string{};
            cell.read_value(value);
            std::cout << "[" << value << "]" << std::endl;
        }
        std::cout << "---" << std::endl;
    }
    std::cout << std::endl;
}

auto test() -> void
{
    test_file("data/test1_lf.csv");
    test_file("data/test2_crlf.csv");
}

auto main() -> int
{
    test();
}
