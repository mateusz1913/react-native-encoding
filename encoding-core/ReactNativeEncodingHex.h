#pragma once

#include <sstream>
#include <string>

std::string decodeFromHexStringToUTF8String(const std::string &hexStr);
std::string encodeFromUTF8StringToHexString(const std::string &utf8Str);
