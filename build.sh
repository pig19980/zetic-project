#!/bin/bash

# 빌드 디렉토리 생성 및 이동
mkdir -p build
cd build

# CMake 실행
cmake ..

# 빌드
cmake --build .
