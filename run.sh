#!/bin/sh
mkdir -p build
cd build
cmake ..
# make && ./rl
make && test/unittest
