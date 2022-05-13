#!/bin/bash
mkdir debug_test_build
cd debug_test_build
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build .

# gdb ./lambda_testd