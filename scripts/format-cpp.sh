#!/bin/bash

clang-format -Werror -i ./{cpp,encoding-core,native-tests}/*.{h,cpp}
