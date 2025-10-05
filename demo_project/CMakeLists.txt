cmake_minimum_required(VERSION 3.30)

project(demo_project)

include(cmake/modules.cmake)

#--- targets ----------------------------------------------------------------------

add_executable(demo_project)

target_sources(demo_project PRIVATE
    "demo_project/demo_project.cpp"
    "demo_project/test.cpp"
    )

target_include_directories(demo_project PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_treat_warnings_as_errors(demo_project)
target_cxx_standard(demo_project 20)
target_set_cxx_base_compile_options(demo_project)

#--- dependencies -----------------------------------------------------------------

find_package(fmt CONFIG REQUIRED)
target_link_libraries(demo_project PRIVATE fmt::fmt)
