cmake_minimum_required(VERSION 3.13)

project(ReactNativeEncodingCore)

set(CMAKE_VERBOSE_MAKEFILE on)

add_library(ReactNativeEncodingCore SHARED
        ${CMAKE_CURRENT_SOURCE_DIR}/ReactNativeEncodingBase64.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/ReactNativeEncodingBase64.h
        ${CMAKE_CURRENT_SOURCE_DIR}/ReactNativeEncodingHex.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/ReactNativeEncodingHex.h)

target_include_directories(ReactNativeEncodingCore PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR})
