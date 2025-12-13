#include "run_tests.h"

auto main() -> int
{
    to_str::test::test_to_str();
    test::run_integration_tests();
}
