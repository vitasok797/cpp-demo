#include <./crow.h>

auto main() -> int
{
    auto app = crow::SimpleApp{};

    CROW_ROUTE(app, "/")([]() { return "Hello from Crow"; });

    // http://localhost:18080/
    app.port(18080).multithreaded().run();
}
