#include <cassert>
#include <iostream>
#include <stdexcept>

namespace test
{

static auto test_ex() -> void
{
    const auto do_trow = []() { throw std::runtime_error{""}; };

    try
    {
        do_trow();
        assert(false && "Exception is not thrown");
    }
    catch (const std::runtime_error&)
    {}
}

auto run_integration_tests() -> void
{
    std::cout << "testing \"integration_tests\": ";

    test_ex();

    std::cout << "OK" << std::endl;
}

}  // namespace test
