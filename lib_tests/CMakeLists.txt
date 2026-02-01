cmake_minimum_required(VERSION 3.30)

project(lib_tests)

include(../demo_project/cmake/modules.cmake)

#--- common --------------------------------------------------------------------------------------

find_package(GTest CONFIG REQUIRED)

function(configure_cxx_options target)
    target_cxx_standard(${target} 20)
    target_set_cxx_base_compile_options(${target})
    target_treat_warnings_as_errors(${target})
endfunction()

function(add_lib_test name)
    set(target "test_${name}")
    set(dependencies ${ARGN})

    add_executable(${target})
    target_link_libraries(${target} PRIVATE GTest::gtest_main GTest::gmock)
    target_sources(${target} PRIVATE "lib_tests/${name}.cpp")
    configure_cxx_options(${target})

    if(dependencies)
        target_link_libraries(${target} PRIVATE ${dependencies})
    endif()
endfunction()

#--- lib tests -----------------------------------------------------------------------------------

find_package(fmt CONFIG REQUIRED)
add_lib_test(fmt fmt::fmt)

find_package(magic_enum CONFIG REQUIRED)
add_lib_test(magic-enum magic_enum::magic_enum)

find_package(Microsoft.GSL CONFIG REQUIRED)
add_lib_test(ms-gsl Microsoft.GSL::GSL)

find_package(nameof CONFIG REQUIRED)
add_lib_test(nameof nameof::nameof)

add_lib_test(p-ranav-csv2)
find_path(P_RANAV_CSV2_INCLUDE_DIRS "csv2/mio.hpp")
target_include_directories(test_p-ranav-csv2 PRIVATE ${P_RANAV_CSV2_INCLUDE_DIRS})

find_package(Poco REQUIRED COMPONENTS Encodings Foundation Net)
add_lib_test(poco Poco::Encodings Poco::Foundation Poco::Net)

find_package(range-v3 CONFIG REQUIRED)
add_lib_test(range-v3 range-v3::meta range-v3::concepts range-v3::range-v3)

find_package(strong_type CONFIG REQUIRED)
add_lib_test(strong-type strong_type::strong_type)

find_package(tabulate CONFIG REQUIRED)
add_lib_test(tabulate tabulate::tabulate)

find_package(tl-ranges CONFIG REQUIRED)
add_lib_test(tl-ranges tl::ranges)
