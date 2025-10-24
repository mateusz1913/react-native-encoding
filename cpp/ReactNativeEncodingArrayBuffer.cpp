#include "ReactNativeEncodingArrayBuffer.h"

namespace facebook::react {

ReactNativeEncodingArrayBuffer::ReactNativeEncodingArrayBuffer(std::vector<uint8_t> data, size_t size)
    : jsi::MutableBuffer(), data_(std::move(data)), size_(size) {}

std::shared_ptr<ReactNativeEncodingArrayBuffer> ReactNativeEncodingArrayBuffer::fromString(const std::string &str) {
    std::vector buffer(str.begin(), str.end());
    auto size = buffer.size();
    return std::make_shared<ReactNativeEncodingArrayBuffer>(std::move(buffer), size);
}

uint8_t *ReactNativeEncodingArrayBuffer::data() {
    return data_.data();
}

size_t ReactNativeEncodingArrayBuffer::size() const {
    return size_;
}

} // namespace facebook::react
