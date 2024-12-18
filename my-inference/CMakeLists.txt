# 최소 CMake 버전
cmake_minimum_required(VERSION 3.10)

# 프로젝트 이름
project(MyInference)

# libtorch 경로 설정
set(TORCH_DIR "/home/libtorch")

# libtorch 라이브러리와 헤더 파일을 찾을 수 있도록 설정
find_package(Torch REQUIRED PATHS ${TORCH_DIR} NO_DEFAULT_PATH)

# 소스 파일들 (src 디렉토리 내의 모든 .cpp 파일을 자동으로 찾음)
file(GLOB SOURCES "src/*.cpp")

# 헤더 파일 디렉토리 (include 디렉토리 내의 모든 .h 파일을 자동으로 찾음)
file(GLOB HEADERS "include/*.h")

# my-inference 라이브러리 생성
add_library(my-inference STATIC ${SOURCES})

# 헤더 파일을 외부에 공개
target_include_directories(my-inference PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${TORCH_INCLUDE_DIRS}
)

# libtorch 라이브러리 링크
target_link_libraries(my-inference PRIVATE ${TORCH_LIBRARIES})
