cmake_minimum_required(VERSION 3.30)

project(test)
include(../_common/CMakeLists.txt)

#--- dependencies -----------------------------------------------------------------

find_package(Poco REQUIRED COMPONENTS Encodings Foundation Net)
target_link_libraries(test PRIVATE Poco::Encodings Poco::Foundation Poco::Net)
