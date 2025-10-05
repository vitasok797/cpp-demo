cmake_minimum_required(VERSION 3.30)

project(test)
include(../_common/CMakeLists.txt)

#--- dependencies -----------------------------------------------------------------

find_package(strong_type CONFIG REQUIRED)
target_link_libraries(test PRIVATE strong_type::strong_type)
