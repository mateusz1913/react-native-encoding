#pragma once

#include <base64.hpp>
#include <cstdint>
#include <string>
#include <string_view>

std::string decodeFromBase64BufferToUtf8String(const uint8_t *data, size_t size);
std::string encodeFromUtf8BufferToBase64String(const uint8_t *data, size_t size);
