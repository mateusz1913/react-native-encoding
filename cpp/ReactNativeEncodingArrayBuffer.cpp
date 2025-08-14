#include "ReactNativeEncodingArrayBuffer.h"

namespace facebook::react {

ReactNativeEncodingArrayBuffer::ReactNativeEncodingArrayBuffer(uint8_t *data, size_t size)
    : jsi::MutableBuffer(), data_(data), size_(size) {}

std::shared_ptr<ReactNativeEncodingArrayBuffer> ReactNativeEncodingArrayBuffer::fromString(const std::string &str) {
    auto buffer = new uint8_t[str.size()];
    std::copy(str.data(), str.data() + str.size(), buffer);
    return std::make_shared<ReactNativeEncodingArrayBuffer>(buffer, str.size());
}

uint8_t *ReactNativeEncodingArrayBuffer::data() {
    return data_;
}

size_t ReactNativeEncodingArrayBuffer::size() const {
    return size_;
}

} // namespace facebook::react
