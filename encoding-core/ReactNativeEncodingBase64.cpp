#include "ReactNativeEncodingBase64.h"

static const uint8_t base64DecodingTable[128] = {
    99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, /* 0 - 15 */
    99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, /* 16 - 31 */
    99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 62, 99, 99, 99, 63, /* 32 - 47 */
    52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 99, 99, 99, 64, 99, 99, /* 48 - 63 */
    99,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, /* 64 - 79 */
    15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 99, 99, 99, 99, 99, /* 80 - 95 */
    99, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, /* 96 - 111 */
    41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 99, 99, 99, 99, 99 /* 112 - 127 */
};
std::string decodeFromBase64BufferToUtf8String(const uint8_t *data, const size_t size) {
    bool pad = data[size - 1] == (uint8_t)'=';
    size_t offset;

    if (pad) {
        offset = ((size / 4) - 1) * 4;
    } else {
        offset = (size / 4) * 4;
    }

    bool isPad1 = data[offset + 2] != (uint8_t)'=';

    std::string decodedStr;
    decodedStr.reserve(offset + (isPad1 ? 2 : 1));

    for (auto p = (uint8_t *) data; p != data + offset; p += 4) {
        uint8_t b1 = base64DecodingTable[p[0]];
        uint8_t b2 = base64DecodingTable[p[1]];
        uint8_t b3 = base64DecodingTable[p[2]];
        uint8_t b4 = base64DecodingTable[p[3]];

        uint32_t quartet = unsigned(b1) << 18 | unsigned(b2) << 12 | unsigned(b3) << 6 | b4;

        decodedStr.push_back((char)(quartet >> 16));
        decodedStr.push_back((char)((quartet >> 8) & 0xFF));
        decodedStr.push_back((char)(quartet & 0xFF));
    }

    if (pad) {
        uint8_t b1 = base64DecodingTable[data[offset]];
        uint8_t b2 = base64DecodingTable[data[offset + 1]];

        uint32_t quartet = unsigned(b1) << 18 | unsigned(b2) << 12;

        decodedStr.push_back((char)(quartet >> 16));

        if (isPad1) {
            uint8_t b3 = base64DecodingTable[data[offset + 2]];

            decodedStr.push_back((char)(((quartet | (unsigned(b3) << 6)) >> 8) & 0xFF));
        }
    }

    return decodedStr;
}

static const std::string base64EncodingTable = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
std::string encodeFromUtf8BufferToBase64String(const uint8_t *data, const size_t size) {
    size_t pad = size % 3;
    size_t last = size - pad;

    size_t encodedStrSize = ((size + 2) / 3) * 4;
    std::string encodedStr (encodedStrSize, '=');

    int i = 0;
    for (auto p = (uint8_t *) data; p != data + last; p += 3) {
        uint32_t triple = unsigned(p[0]) << 16 | unsigned(p[1]) << 8 | p[2];

        encodedStr[i++] = base64EncodingTable[triple >> 18];
        encodedStr[i++] = base64EncodingTable[(triple >> 12) & 0x3F];
        encodedStr[i++] = base64EncodingTable[(triple >> 6) & 0x3F];
        encodedStr[i++] = base64EncodingTable[triple & 0x3F];
    }

    if (pad) {
        uint8_t *p = (uint8_t *) data + last;

        if (pad == 1) {
            auto triple = unsigned(p[0]);

            encodedStr[i++] = base64EncodingTable[triple >> 2];
            encodedStr[i++] = base64EncodingTable[(triple << 4) & 0x3F];
        } else if (pad == 2) {
            auto triple = unsigned(p[0]) << 8 | p[1];

            encodedStr[i++] = base64EncodingTable[triple >> 10];
            encodedStr[i++] = base64EncodingTable[(triple >> 4) & 0x3F];
            encodedStr[i++] = base64EncodingTable[(triple << 2) & 0x3F];
        }
    }

    return encodedStr;
}
