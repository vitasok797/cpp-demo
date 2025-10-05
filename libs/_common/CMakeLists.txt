cmake_minimum_required(VERSION 3.30)

include(../../demo_project/cmake/modules.cmake)

add_executable(test)

target_sources(test PRIVATE "main.cpp")

target_treat_warnings_as_errors(test)
target_cxx_standard(test 20)
target_set_cxx_base_compile_options(test)
