#include <strong_type/strong_type.hpp>

#include <iostream>

using MyInt = strong::type<int, struct MyInt_tag>;
using MyInt2 = strong::type<int, struct MyInt2_tag, strong::regular, strong::ordered>;

auto print_my_int(const MyInt& value) -> void
{
    std::cout << value_of(value) << std::endl;
    std::cout << value.value_of() << std::endl;
}

auto test() -> void
{
    // function argument
    {
        print_my_int(MyInt{42});
        // print_my_int(MyInt2{42});  // error
        // print_my_int(42);  // error
    }

    // equality
    {
        std::cout << "== : " << (MyInt2{42} == MyInt2{42}) << std::endl;
        std::cout << "!==: " << (MyInt2{42} == MyInt2{1}) << std::endl;
        std::cout << ">  : " << (MyInt2{42} > MyInt2{1}) << std::endl;
    }
}

auto main() -> int
{
    test();
}
