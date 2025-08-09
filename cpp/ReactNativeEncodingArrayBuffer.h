#pragma once

#include <jsi/jsi.h>

namespace facebook::react {

class ReactNativeEncodingArrayBuffer : public jsi::MutableBuffer {
public:
    explicit ReactNativeEncodingArrayBuffer(const std::string &str);
    explicit ReactNativeEncodingArrayBuffer(uint8_t *data, size_t size);

    [[nodiscard]] size_t size() const override;
    uint8_t *data() override;

private:
    uint8_t *data_;
    size_t size_;
};

} // namespace facebook::react
