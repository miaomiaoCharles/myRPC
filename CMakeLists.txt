cmake_minimum_required(VERSION 3.0)
project(mprpc)
set(CMAKE_BUILD_TYPE "Debug")  #生成debug版本可以调试

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
include_directories(${PROJECT_SOURCE_DIR}/src/include)
include_directories(${PROJECT_SOURCE_DIR}/example)
include_directories(${PROJECT_SOURCE_DIR}/example/callee)
include_directories(${PROJECT_SOURCE_DIR}/example/caller)
link_directories(${PROJECT_SOURCE_DIR}/lib)
add_subdirectory(src)  #src继续去找相应的cmakelist
add_subdirectory(example)