#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <./exprtk.hpp>

#include <string>

TEST(ExprtkTest, Main)
{
    const auto expression_string = std::string{"x*2"};

    double x;

    auto symbol_table = exprtk::symbol_table<double>{};
    symbol_table.add_variable("x", x);
    symbol_table.add_constants();

    auto expression = exprtk::expression<double>{};
    expression.register_symbol_table(symbol_table);

    auto parser = exprtk::parser<double>{};
    parser.compile(expression_string, expression);

    x = 10.0;
    EXPECT_EQ(expression.value(), 20.0);
}
