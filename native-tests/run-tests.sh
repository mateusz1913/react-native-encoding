#!/bin/sh
DIRNAME=$(realpath $(dirname $0))
ctest --test-dir $DIRNAME/build
if [ $? -ne 0 ];
then
    echo 'Test suite run failed';
    exit 1;
fi
