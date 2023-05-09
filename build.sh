#!/bin/bash
#build script for the application.

#cd to the script directory so you can run it from anywhere
cd "$(dirname "$0")"

mkdir -p build
mkdir -p bin
cd build
cmake ../
make
