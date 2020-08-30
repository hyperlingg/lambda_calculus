#!/bin/bash
mkdir test_build
cd test_build
cmake ..
cmake --build .
./lambda_test --log_level=test_suite