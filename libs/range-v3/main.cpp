#include <range/v3/all.hpp>

#include <iostream>
#include <vector>

template<typename T>
auto print_vector(const std::vector<T>& v) -> void
{
    for (const auto& item : v)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

auto test() -> void
{
    {
        auto v = std::vector{4, 5, 2, 3, 1};
        ranges::sort(v);
        print_vector(v);  // 1 2 3 4 5
    }
    {
        auto v = std::vector{2, 1, 2, 3, 1};
        v |= ranges::actions::sort | ranges::actions::unique;
        print_vector(v);  // 1 2 3
    }
    {
        auto v = std::vector<std::string>{"A", "B", "C"};

        for (const auto& [index, value] : ranges::views::enumerate(v))
        {
            std::cout << index << ":" << value << " ";  // 0:A 1:B 2:C
        }
        std::cout << std::endl;
    }
    {
        const auto v = std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        auto v2 = v | ranges::views::remove_if([](int i) { return i % 2 == 1; })
                  | ranges::views::transform([](int i) { return std::string{"i"} + std::to_string(i); })
                  | ranges::to<std::vector>();
        print_vector(v2);  // i2, i4, i6, i8, i10
    }
    {
        const auto v = std::vector<int>{1, 2, 3, 4, 5};
        auto r = v | ranges::views::transform([](int i) { return i * 10; });

        // x10 x20 x30 x40 x50
        ranges::for_each(r, [](int i) { std::cout << "x" << i << " "; });
        std::cout << std::endl;

        // 10 20 30 40 50
        print_vector(ranges::to<std::vector>(r));
    }
}

auto main() -> int
{
    test();
}
