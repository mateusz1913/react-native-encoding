#pragma once

#include <RNEncodingModulesJSI.h>

#include <memory>
#include <string>

namespace facebook::react {

class ReactNativeEncodingModule : public NativeReactNativeEncodingModuleCxxSpec<ReactNativeEncodingModule> {
public:
    explicit ReactNativeEncodingModule(std::shared_ptr<CallInvoker> jsInvoker);

    std::string convertFromArrayBufferToBase64(jsi::Runtime &rt, jsi::Object arrayBuffer);
    std::string convertFromArrayBufferToHex(jsi::Runtime &rt, jsi::Object arrayBuffer);
    std::string convertFromArrayBufferToUTF8(jsi::Runtime &rt, jsi::Object arrayBuffer);

    jsi::Object convertFromBase64ToArrayBuffer(jsi::Runtime &rt, const std::string &base64Str);
    std::string convertFromBase64ToHex(jsi::Runtime &rt, const std::string &base64Str);
    std::string convertFromBase64ToUTF8(jsi::Runtime &rt, const std::string &base64Str);

    jsi::Object convertFromHexToArrayBuffer(jsi::Runtime &rt, const std::string &hexStr);
    std::string convertFromHexToBase64(jsi::Runtime &rt, const std::string &hexStr);
    std::string convertFromHexToUTF8(jsi::Runtime &rt, const std::string &hexStr);

    jsi::Object convertFromUTF8ToArrayBuffer(jsi::Runtime &rt, const std::string &utf8Str);
    std::string convertFromUTF8ToBase64(jsi::Runtime &rt, const std::string &utf8Str);
    std::string convertFromUTF8ToHex(jsi::Runtime &rt, const std::string &utf8Str);
};

} // namespace facebook::react
