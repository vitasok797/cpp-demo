#include <fmt/core.h>
#include <fmt/ranges.h>

#include <vector>

auto test() -> void
{
    fmt::print("Lib fmt version is {}\n", FMT_VERSION);

    auto s1 = fmt::format("The answer is {}", 42);
    fmt::print("{}\n", s1);

    auto s2 = fmt::format("I'd rather be {1} than {0}", "right", "happy");
    fmt::print("{}\n", s2);

    fmt::print("{}\n", fmt::to_string(333));

    auto v = std::vector<int>{1, 2, 3};
    fmt::print("{}\n", v);
}

auto main() -> int
{
    test();
}
