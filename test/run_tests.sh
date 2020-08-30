#!/bin/bash
mkdir test_build
cd test_build
cmake ..
cmake --build .
ctest -VV