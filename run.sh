#!/bin/sh
mkdir -p build
cd build
cmake ..
make && demo/cellular
#make && test/rltest
