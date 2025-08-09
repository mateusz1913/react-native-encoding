cmake_minimum_required(VERSION 3.13)

project(ReactNativeEncodingTests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../encoding-core ReactNativeEncodingCore_build)

enable_testing()

add_executable(ReactNativeEncodingTests
        ReactNativeEncodingTests.cpp)

target_include_directories(ReactNativeEncodingTests
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(ReactNativeEncodingTests
        PRIVATE
        GTest::gtest_main
        ReactNativeEncodingCore)

include(GoogleTest)
gtest_discover_tests(ReactNativeEncodingTests)
