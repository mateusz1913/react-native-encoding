#include "ReactNativeEncodingBase64.h"

std::string decodeFromBase64BufferToUtf8String(const uint8_t *data, const size_t size) {
    std::string_view str_view(reinterpret_cast<const char *>(data), size);
    return base64::from_base64(str_view);
}

std::string encodeFromUtf8BufferToBase64String(const uint8_t *data, const size_t size) {
    std::string_view str_view(reinterpret_cast<const char *>(data), size);
    return base64::to_base64(str_view);
}
