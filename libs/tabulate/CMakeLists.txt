cmake_minimum_required(VERSION 3.30)

project(test)
include(../_common/CMakeLists.txt)

#--- dependencies -----------------------------------------------------------------

find_package(tabulate CONFIG REQUIRED)
target_link_libraries(test PRIVATE tabulate::tabulate)
