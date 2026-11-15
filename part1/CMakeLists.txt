cmake_minimum_required(VERSION 3.16)
project(resistor_tdd LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set (CMAKE_EXPORT_COMPILE_COMMANDS 1)

add_library(resistor
    src/Resistor.cpp
)

target_include_directories(resistor
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

include(CTest)

if(BUILD_TESTING)
    include(FetchContent)

    FetchContent_Declare(googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    FetchContent_MakeAvailable(googletest)

    add_executable(resistor_tests
        tests/test_resistor.cpp
    )

    target_link_libraries(resistor_tests
        PRIVATE resistor GTest::gtest_main
    )

    include(GoogleTest)

    gtest_discover_tests(resistor_tests)
endif()
