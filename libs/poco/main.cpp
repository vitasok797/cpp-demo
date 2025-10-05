#include <Poco/AutoPtr.h>
#include <Poco/ConsoleChannel.h>
#include <Poco/FormattingChannel.h>
#include <Poco/Logger.h>
#include <Poco/Message.h>
#include <Poco/PatternFormatter.h>

auto test() -> void
{
    auto console_ch = Poco::AutoPtr{new Poco::ConsoleChannel{}};
    auto pattern_formatter = Poco::AutoPtr{new Poco::PatternFormatter{"[%O] %s / %p / %t"}};
    auto formatting_ch = Poco::AutoPtr{
        new Poco::FormattingChannel{pattern_formatter, console_ch}
    };

    auto& console_logger = Poco::Logger::create("ConsoleLogger", formatting_ch, Poco::Message::PRIO_INFORMATION);

    console_logger.error("error");
    console_logger.warning("warning");

    poco_warning(console_logger, "warning macro");
    poco_warning_f2(console_logger, "warning macro with arguments: %d, %d", 1, 2);

    Poco::Logger::get("ConsoleLogger").error("via get error message");
    Poco::Logger::root().warning("root warning");
}

auto main() -> int
{
    test();
}
