#include <tl/enumerate.hpp>
#include <tl/to.hpp>

#include <iostream>
#include <ranges>
#include <vector>

auto test() -> void
{
    auto vec = std::vector{1, 2, 3, 4, 5};

    auto vec2 = vec                                                     //
                | std::views::reverse                                   //
                | std::views::take(3)                                   //
                | std::views::transform([](auto i) { return i * 10; })  //
                | tl::views::enumerate                                  //
                | tl::to<std::vector>();                                //

    std::ranges::for_each(vec2, [](auto pair) { std::cout << "(" << pair.first << "," << pair.second << ")"; });
    std::cout << std::endl;
}

auto main() -> int
{
    test();
}
