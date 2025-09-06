#pragma once

#include <cstdint>
#include <string>

std::string decodeFromBase64BufferToUtf8String(const uint8_t *data, size_t size);
std::string encodeFromUtf8BufferToBase64String(const uint8_t *data, size_t size);
