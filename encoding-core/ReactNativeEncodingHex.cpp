#include "ReactNativeEncodingHex.h"

static const uint8_t hexDecodingTable[128] = {
    99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, /* 0 - 15 */
    99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, /* 16 - 31 */
    99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, /* 32 - 47 */
    0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  99, 99, 99, 99, 99, 99, /* 48 - 63 */
    99, 10, 11, 12, 13, 14, 15, 99, 99, 99, 99, 99, 99, 99, 99, 99, /* 64 - 79 */
    99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, /* 80 - 95 */
    99, 10, 11, 12, 13, 14, 15, 99, 99, 99, 99, 99, 99, 99, 99, 99, /* 96 - 111 */
    99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99 /* 112 - 127 */
};
std::string decodeFromHexStringToUTF8String(const std::string &hexStr) {
    auto data = reinterpret_cast<const uint8_t *>(hexStr.c_str());
    auto size = hexStr.length();

    std::string utf8Str;
    utf8Str.reserve((size / 2));

    for (size_t i = 0; i < size; i += 2) {
        uint8_t b1 = hexDecodingTable[hexStr[i]];
        uint8_t b2 = hexDecodingTable[hexStr[i + 1]];

        utf8Str.push_back((char)((b1 << 4) | b2));
    }

    return utf8Str;
}

static char hexDictionary[] = "0123456789abcdef";
std::string encodeFromUTF8StringToHexString(const std::string &utf8Str) {
    auto data = reinterpret_cast<const uint8_t *>(utf8Str.c_str());
    auto size = utf8Str.length();

    std::string hexStr;
    hexStr.reserve(size * 2);

    for (size_t i = 0; i < size; i++) {
        hexStr.push_back(hexDictionary[((data[i] & 0xF0) >> 4)]);
        hexStr.push_back(hexDictionary[(data[i] & 0x0F)]);
    }

    return hexStr;
}
