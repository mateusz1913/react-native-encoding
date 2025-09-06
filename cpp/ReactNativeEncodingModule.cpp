#include "ReactNativeEncodingModule.h"
#include "ReactNativeEncodingArrayBuffer.h"
#include "ReactNativeEncodingBase64.h"
#include "ReactNativeEncodingHex.h"

namespace facebook::react {

ReactNativeEncodingModule::ReactNativeEncodingModule(std::shared_ptr<CallInvoker> jsInvoker)
    : NativeReactNativeEncodingModuleCxxSpec(std::move(jsInvoker)) {}

std::string ReactNativeEncodingModule::convertFromArrayBufferToBase64(jsi::Runtime &rt, jsi::Object arrayBuffer) {
    if (!arrayBuffer.isArrayBuffer(rt)) {
        throw jsi::JSError(rt, "argument should be an instance of ArrayBuffer");
    }

    auto buffer = arrayBuffer.getArrayBuffer(rt);

    std::string encodedStr = encodeFromUtf8BufferToBase64String(buffer.data(rt), buffer.size(rt));

    return encodedStr;
}

std::string ReactNativeEncodingModule::convertFromArrayBufferToHex(jsi::Runtime &rt, jsi::Object arrayBuffer) {
    if (!arrayBuffer.isArrayBuffer(rt)) {
        throw jsi::JSError(rt, "argument should be an instance of ArrayBuffer");
    }

    auto buffer = arrayBuffer.getArrayBuffer(rt);

    std::string str(reinterpret_cast<char *>(buffer.data(rt)), buffer.size(rt));
    std::string encodedStr = encodeFromUTF8StringToHexString(str);

    return encodedStr;
}

std::string ReactNativeEncodingModule::convertFromArrayBufferToUTF8(jsi::Runtime &rt, jsi::Object arrayBuffer) {
    if (!arrayBuffer.isArrayBuffer(rt)) {
        throw jsi::JSError(rt, "argument should be an instance of ArrayBuffer");
    }

    auto buffer = arrayBuffer.getArrayBuffer(rt);

    std::string utf8Str(reinterpret_cast<char *>(buffer.data(rt)), buffer.size(rt));

    return utf8Str;
}

jsi::Object ReactNativeEncodingModule::convertFromBase64ToArrayBuffer(jsi::Runtime &rt, const std::string &base64Str) {
    auto data = reinterpret_cast<const uint8_t *>(base64Str.c_str());
    auto size = base64Str.length();

    std::string decodedStr = decodeFromBase64BufferToUtf8String(data, size);

    auto arrayBufferWrapper = ReactNativeEncodingArrayBuffer::fromString(decodedStr);

    return jsi::ArrayBuffer(rt, arrayBufferWrapper);
}

std::string ReactNativeEncodingModule::convertFromBase64ToHex(jsi::Runtime &rt, const std::string &base64Str) {
    auto data = reinterpret_cast<const uint8_t *>(base64Str.c_str());
    auto size = base64Str.length();

    std::string decodedStr = decodeFromBase64BufferToUtf8String(data, size);
    std::string encodedStr = encodeFromUTF8StringToHexString(decodedStr);

    return encodedStr;
}

std::string ReactNativeEncodingModule::convertFromBase64ToUTF8(jsi::Runtime &rt, const std::string &base64Str) {
    auto data = reinterpret_cast<const uint8_t *>(base64Str.c_str());
    auto size = base64Str.length();

    std::string decodedStr = decodeFromBase64BufferToUtf8String(data, size);

    return decodedStr;
}

jsi::Object ReactNativeEncodingModule::convertFromHexToArrayBuffer(jsi::Runtime &rt, const std::string &hexStr) {
    std::string decodedStr = decodeFromHexStringToUTF8String(hexStr);

    auto arrayBufferWrapper = ReactNativeEncodingArrayBuffer::fromString(decodedStr);

    return jsi::ArrayBuffer(rt, arrayBufferWrapper);
}

std::string ReactNativeEncodingModule::convertFromHexToBase64(jsi::Runtime &rt, const std::string &hexStr) {
    std::string decodedStr = decodeFromHexStringToUTF8String(hexStr);

    auto data = reinterpret_cast<const uint8_t *>(decodedStr.c_str());
    auto size = decodedStr.length();

    std::string encodedStr = encodeFromUtf8BufferToBase64String(data, size);

    return encodedStr;
}

std::string ReactNativeEncodingModule::convertFromHexToUTF8(jsi::Runtime &rt, const std::string &hexStr) {
    std::string decodedStr = decodeFromHexStringToUTF8String(hexStr);

    return decodedStr;
}

jsi::Object ReactNativeEncodingModule::convertFromUTF8ToArrayBuffer(jsi::Runtime &rt, const std::string &utf8Str) {
    auto arrayBufferWrapper = ReactNativeEncodingArrayBuffer::fromString(utf8Str);

    return jsi::ArrayBuffer(rt, arrayBufferWrapper);
}

std::string ReactNativeEncodingModule::convertFromUTF8ToBase64(jsi::Runtime &rt, const std::string &utf8Str) {
    auto data = reinterpret_cast<const uint8_t *>(utf8Str.c_str());
    auto size = utf8Str.length();

    std::string encodedStr = encodeFromUtf8BufferToBase64String(data, size);

    return encodedStr;
}

std::string ReactNativeEncodingModule::convertFromUTF8ToHex(jsi::Runtime &rt, const std::string &utf8Str) {
    std::string encodedStr = encodeFromUTF8StringToHexString(utf8Str);

    return encodedStr;
}

} // namespace facebook::react
