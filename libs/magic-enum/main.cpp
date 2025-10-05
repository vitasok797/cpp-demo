#include <magic_enum/magic_enum.hpp>

#include <iostream>

enum class Color
{
    none,
    red,
    blue,
    green
};

auto test() -> void
{
    // enum to string
    {
        auto color = Color::red;
        std::cout << magic_enum::enum_name(color) << std::endl;
    }

    // string to enum
    {
        auto color_opt = magic_enum::enum_cast<Color>("grEEn", magic_enum::case_insensitive);
        if (color_opt.has_value())
        {
            std::cout << magic_enum::enum_name(color_opt.value()) << std::endl;
        }
    }

    // string to enum (with default)
    {
        auto color = magic_enum::enum_cast<Color>("xxx").value_or(Color::none);
        std::cout << magic_enum::enum_name(color) << std::endl;
    }

    // integer to enum value
    {
        auto color = magic_enum::enum_cast<Color>(2).value_or(Color::none);
        std::cout << magic_enum::enum_name(color) << std::endl;
    }

    // number of enum elements
    {
        constexpr auto color_count = magic_enum::enum_count<Color>();
        std::cout << "Color count: " << color_count << std::endl;
    }

    // check if enum contains
    {
        std::cout << "Check 2: " << magic_enum::enum_contains<Color>(2) << std::endl;
        std::cout << "Check 123: " << magic_enum::enum_contains<Color>(123) << std::endl;
        std::cout << "Check green: " << magic_enum::enum_contains<Color>("green") << std::endl;
        std::cout << "Check black: " << magic_enum::enum_contains<Color>("black") << std::endl;
    }
}

auto main() -> int
{
    test();
}
