#!/bin/sh
mkdir -p build
cd build
cmake ..
make && demo/random
#make && demo/cellular
#make && test/rltest
