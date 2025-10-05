cmake_minimum_required(VERSION 3.30)

project(test)
include(../_common/CMakeLists.txt)

#--- dependencies -----------------------------------------------------------------

find_package(magic_enum CONFIG REQUIRED)
target_link_libraries(test PRIVATE magic_enum::magic_enum)
