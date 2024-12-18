# my-inference/CMakeLists.txt

# 최소 CMake 버전
cmake_minimum_required(VERSION 3.10)

# 라이브러리 이름
project(MyInference)

# libtorch 경로 설정
set(TORCH_DIR "/home/libtorch")

# libtorch 라이브러리와 헤더 파일을 찾을 수 있도록 설정
find_package(Torch REQUIRED PATHS ${TORCH_DIR})


# 소스 파일들
set(SOURCES
    src/mylib.cpp
)

# 헤더 파일 디렉토리
set(HEADERS
    include/mylib.h
)

# my-inference 라이브러리 생성
add_library(my-inference STATIC ${SOURCES})

# 헤더 파일을 외부에 공개
target_include_directories(my-inference PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# libtorch 라이브러리 링크
target_link_libraries(my-inference PRIVATE ${TORCH_LIBRARIES})