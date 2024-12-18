# 최소 CMake 버전 설정
cmake_minimum_required(VERSION 3.10)

# 프로젝트 이름과 버전 설정
project(MyProject VERSION 1.0)

# C++ 표준 설정
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 라이브러리 소스 디렉토리와 포함 경로 설정
include_directories(${CMAKE_SOURCE_DIR}/include)

# 라이브러리 경로 설정
add_subdirectory(my-inference)

# 실행 파일 컴파일
add_executable(my-project src/main.cpp)

# 라이브러리 링크 설정
target_link_libraries(my-project PRIVATE my-inference)


