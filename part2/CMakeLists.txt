cmake_minimum_required(VERSION 3.16)

project(lab02-part2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set (CMAKE_EXPORT_COMPILE_COMMANDS 1)

add_library(sensor_monitoring
    src/MeasurementHistory.cpp
    src/TemperatureSensor.cpp
    src/SensorStation.cpp
)

target_include_directories(sensor_monitoring 
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(sensor_demo 
    app/main.cpp
)

target_link_libraries(sensor_demo 
    PRIVATE sensor_monitoring
)

include(CTest)
if(BUILD_TESTING)
    include(FetchContent)
    FetchContent_Declare(googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
    add_executable(sensor_tests tests/test_sensor_monitoring.cpp)
    target_link_libraries(sensor_tests PRIVATE sensor_monitoring GTest::gtest_main)
    include(GoogleTest)
    gtest_discover_tests(sensor_tests)
endif()
