cmake_minimum_required(VERSION 3.13)

project(ReactNativeEncoding)

set(CMAKE_VERBOSE_MAKEFILE on)

add_library(ReactNativeEncoding SHARED
        ${CMAKE_CURRENT_SOURCE_DIR}/ReactNativeEncodingArrayBuffer.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/ReactNativeEncodingArrayBuffer.h
        ${CMAKE_CURRENT_SOURCE_DIR}/ReactNativeEncodingModule.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/ReactNativeEncodingModule.h)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../encoding-core ReactNativeEncodingCore_build)

target_include_directories(ReactNativeEncoding PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(ReactNativeEncoding
        android
        log
        react_codegen_RNEncodingModules
        ReactNativeEncodingCore)
