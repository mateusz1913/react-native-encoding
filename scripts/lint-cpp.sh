#!/bin/bash

clang-format --dry-run -i ./{cpp,encoding-core,native-tests}/*.{h,cpp}
