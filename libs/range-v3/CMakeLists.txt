cmake_minimum_required(VERSION 3.30)

project(test)
include(../_common/CMakeLists.txt)

#--- dependencies -----------------------------------------------------------------

find_package(range-v3 CONFIG REQUIRED)
target_link_libraries(test PRIVATE range-v3::meta range-v3::concepts range-v3::range-v3)
