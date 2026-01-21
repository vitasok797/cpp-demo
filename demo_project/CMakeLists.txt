cmake_minimum_required(VERSION 3.30)

project(demo_project)

include(cmake/modules.cmake)

#--- common --------------------------------------------------------------------------------------

function(configure_cxx_options target)
    target_cxx_standard(${target} 20)
    target_set_cxx_base_compile_options(${target})
    target_treat_warnings_as_errors(${target})
endfunction()

# set(DEBUG_POSTFIX "_x64_Debug")
# set_libraries_debug_postfix(${DEBUG_POSTFIX})

# add_linux_relative_so_search_path(".")

#--- dependencies --------------------------------------------------------------------------------

set(CUR_TARGET dependencies)
add_library(${CUR_TARGET} INTERFACE)

find_package(fmt CONFIG REQUIRED)
target_link_libraries(${CUR_TARGET} INTERFACE fmt::fmt)

#--- demo_project lib ----------------------------------------------------------------------------

set(CUR_TARGET lib_demo_project)
add_library(${CUR_TARGET} STATIC)

target_link_libraries(${CUR_TARGET} PUBLIC dependencies)
target_include_directories(${CUR_TARGET} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
configure_cxx_options(${CUR_TARGET})

target_sources(${CUR_TARGET} PRIVATE
    "demo_project/to_str.cpp"
    )

#--- demo_project executable ---------------------------------------------------------------------

set(CUR_TARGET demo_project)
add_executable(${CUR_TARGET})

target_link_libraries(${CUR_TARGET} PRIVATE lib_demo_project)
configure_cxx_options(${CUR_TARGET})

target_sources(${CUR_TARGET} PRIVATE
    "demo_project/demo_project.cpp"
    )

#--- tests executable ----------------------------------------------------------------------------

option(DEMO_PROJECT_BUILD_TESTS "Build tests" ON)

if(DEMO_PROJECT_BUILD_TESTS AND "${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
    set(CUR_TARGET run_tests)
    add_executable(${CUR_TARGET})

    target_link_libraries(${CUR_TARGET} PRIVATE lib_demo_project)
    configure_cxx_options(${CUR_TARGET})

    target_sources(${CUR_TARGET} PRIVATE
        "demo_project/to_str.test.cpp"
        "test/integration_tests.cpp"
        "test/run_tests.cpp"
        )
endif()
