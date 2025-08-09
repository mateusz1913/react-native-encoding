#include "ReactNativeEncodingArrayBuffer.h"

namespace facebook::react {

ReactNativeEncodingArrayBuffer::ReactNativeEncodingArrayBuffer(const std::string &str)
    : jsi::MutableBuffer(), data_((uint8_t *)str.c_str()), size_(str.length()) {}

ReactNativeEncodingArrayBuffer::ReactNativeEncodingArrayBuffer(uint8_t *data, size_t size)
    : jsi::MutableBuffer(), data_(data), size_(size) {}

uint8_t *ReactNativeEncodingArrayBuffer::data() {
    return data_;
}

size_t ReactNativeEncodingArrayBuffer::size() const {
    return size_;
}

} // namespace facebook::react
