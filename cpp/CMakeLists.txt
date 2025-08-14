#
# Library must be STATIC to make it possible to link codegened-spec library to it
# Should have `CMAKE_CXX_STANDARD` set
#
# `android/build.gradle` must declare buildFeature.prefab = true
#
cmake_minimum_required(VERSION 3.13)

project(ReactNativeEncoding)

set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_CXX_STANDARD 20)

find_package(ReactAndroid REQUIRED CONFIG)

add_library(ReactNativeEncoding STATIC
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
        ReactAndroid::jsi
        ReactAndroid::reactnative
        react_codegen_RNEncodingModules
        ReactNativeEncodingCore)
