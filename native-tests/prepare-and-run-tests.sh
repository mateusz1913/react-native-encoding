#!/bin/sh
DIRNAME=$(realpath $(dirname $0))
# Generate dataset
$DIRNAME/../scripts/generate-cpp-dataset.js
# Prepare build files with CMake
cmake -S $DIRNAME -B $DIRNAME/build
if [ $? -ne 0 ];
then
    echo 'Build files preparation failed';
    exit 1;
fi
# Build test suite
cmake --build $DIRNAME/build
if [ $? -ne 0 ];
then
    echo 'Test suite build failed';
    exit 1;
fi
# Run test suite
$DIRNAME/run-tests.sh
