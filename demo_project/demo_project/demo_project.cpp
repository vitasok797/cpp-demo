#include "demo_project.h"

#include <demo_project/test.h>

#include <fmt/core.h>

auto main() -> int
{
    fmt::print("Hello World!\n");

    fmt::print("App version is {}\n", DEMO_PROJECT_VERSION);
    fmt::print("Lib fmt version is {}\n", FMT_VERSION);

    test();
}
