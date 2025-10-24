#pragma once

#include <vector>

#include <jsi/jsi.h>

namespace facebook::react {

class ReactNativeEncodingArrayBuffer : public jsi::MutableBuffer {
public:
    explicit ReactNativeEncodingArrayBuffer(std::vector<uint8_t> data, size_t size);

    static std::shared_ptr<ReactNativeEncodingArrayBuffer> fromString(const std::string &str);

    [[nodiscard]] size_t size() const override;
    uint8_t *data() override;

private:
    std::vector<uint8_t> data_;
    size_t size_;
};

} // namespace facebook::react
