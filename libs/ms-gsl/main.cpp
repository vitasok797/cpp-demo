#include <gsl/narrow>
#include <gsl/util>

#include <iostream>

auto test() -> void
{
    auto x1 = size_t{1};
    [[maybe_unused]] int x2 = gsl::narrow_cast<int>(x1);

    try
    {
        auto x3 = int{-1};
        [[maybe_unused]] size_t x4 = gsl::narrow<size_t>(x3);
    }
    catch (const gsl::narrowing_error&)
    {
        std::cout << "narrowing_error" << std::endl;
    }
}

auto main() -> int
{
    test();
}
