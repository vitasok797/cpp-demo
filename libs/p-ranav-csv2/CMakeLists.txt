cmake_minimum_required(VERSION 3.30)

project(test)
include(../_common/CMakeLists.txt)

#--- dependencies -----------------------------------------------------------------

find_path(P_RANAV_CSV2_INCLUDE_DIRS "csv2/mio.hpp")
target_include_directories(test PRIVATE ${P_RANAV_CSV2_INCLUDE_DIRS})
