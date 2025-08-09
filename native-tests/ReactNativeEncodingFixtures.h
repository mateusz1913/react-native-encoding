#pragma once

#include <gtest/gtest.h>
#include <string>

#include "ReactNativeEncodingDataset.h"

class Base64DecodeTest : public ::testing::TestWithParam<Dataset> {
protected:
    std::string input;
    std::string output;

    void SetUp() override {
        auto dataset = GetParam();

        this->input = std::get<1>(dataset);
        this->output = std::get<0>(dataset);
    }
};

class Base64EncodeTest : public ::testing::TestWithParam<Dataset> {
protected:
    std::string input;
    std::string output;

    void SetUp() override {
        auto dataset = GetParam();

        this->input = std::get<0>(dataset);
        this->output = std::get<1>(dataset);
    }
};

class HexDecodeTest : public ::testing::TestWithParam<Dataset> {
protected:
    std::string input;
    std::string output;

    void SetUp() override {
        auto dataset = GetParam();

        this->input = std::get<2>(dataset);
        this->output = std::get<0>(dataset);
    }
};

class HexEncodeTest : public ::testing::TestWithParam<Dataset> {
protected:
    std::string input;
    std::string output;

    void SetUp() override {
        auto dataset = GetParam();

        this->input = std::get<0>(dataset);
        this->output = std::get<2>(dataset);
    }
};
