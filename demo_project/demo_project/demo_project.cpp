#include "demo_project.h"

#include <demo_project/to_str.h>

#include <fmt/format.h>

auto main() -> int
{
    fmt::println("Hello World!");

    fmt::println("App version is {}", DEMO_PROJECT_VERSION);
    fmt::println("Lib fmt version is {}", FMT_VERSION);

    fmt::println("{}", to_str::int_to_str(123));
}
