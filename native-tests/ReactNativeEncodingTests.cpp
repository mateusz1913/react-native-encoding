#include <gtest/gtest.h>
#include <format>

#include "ReactNativeEncodingBase64.h"
#include "ReactNativeEncodingDataset.h"
#include "ReactNativeEncodingFixtures.h"
#include "ReactNativeEncodingHex.h"

TEST_P(Base64DecodeTest, ShouldDecodeBase64BufferToUTF8String) {
    auto result = decodeFromBase64BufferToUtf8String(reinterpret_cast<const uint8_t *>(this->input.data()), this->input.length());
    EXPECT_EQ(result, this->output);
}

INSTANTIATE_TEST_SUITE_P(Base64DecodeTestSuite,
    Base64DecodeTest,
    testing::ValuesIn(dataset),
    [](const testing::TestParamInfo<Base64DecodeTest::ParamType> &info) {
        return std::to_string(info.index);
    });

TEST_P(Base64EncodeTest, ShouldEncodeUTF8BufferToBase64String) {
    auto result = encodeFromUtf8BufferToBase64String(reinterpret_cast<const uint8_t *>(this->input.data()), this->input.length());
    EXPECT_EQ(result, this->output);
}

INSTANTIATE_TEST_SUITE_P(Base64EncodeTestSuite,
    Base64EncodeTest,
    testing::ValuesIn(dataset),
    [](const testing::TestParamInfo<Base64EncodeTest::ParamType> &info) {
        return std::to_string(info.index);
    });

TEST_P(HexDecodeTest, ShouldDecodeHexStringToUTF8String) {
    auto result = decodeFromHexStringToUTF8String(this->input);
    EXPECT_EQ(result, this->output);
}

INSTANTIATE_TEST_SUITE_P(HexDecodeTestSuite,
    HexDecodeTest,
    testing::ValuesIn(dataset),
    [](const testing::TestParamInfo<HexDecodeTest::ParamType> &info) {
        return std::to_string(info.index);
    });

TEST_P(HexEncodeTest, ShouldEncodeUTF8StringToHexString) {
    auto result = encodeFromUTF8StringToHexString(this->input);
    EXPECT_EQ(result, this->output);
}

INSTANTIATE_TEST_SUITE_P(HexEncodeTestSuite,
    HexEncodeTest,
    testing::ValuesIn(dataset),
    [](const testing::TestParamInfo<HexEncodeTest::ParamType> &info) {
        return std::to_string(info.index);
    });
