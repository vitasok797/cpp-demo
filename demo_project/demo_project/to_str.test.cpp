#include "to_str.h"

#include <cassert>
#include <iostream>

namespace to_str::test
{

static auto test_int_to_str() -> void
{
    assert(int_to_str(123) == "123");
}

auto test_to_str() -> void
{
    std::cout << "testing \"to_str\": ";

    test_int_to_str();

    std::cout << "OK" << std::endl;
}

}  // namespace to_str::test
