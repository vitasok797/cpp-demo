#include "to_str.h"

#include <fmt/format.h>

namespace to_str
{

auto int_to_str(int value) -> std::string
{
    return fmt::format("{}", value);
}

}  // namespace to_str
