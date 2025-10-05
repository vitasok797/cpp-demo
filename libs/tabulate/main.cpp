#include <tabulate/table.hpp>

auto test() -> void
{
    auto table = tabulate::Table{};

    table.add_row({"Col 1", "Col 2"});
    table.add_row({"AAA", "111"});
    table.add_row({"BBB", "222"});
    table.add_row({"CCC", "333"});

    table[0].format().font_color(tabulate::Color::red);

    std::cout << table << std::endl;
}

auto main() -> int
{
    test();
}
