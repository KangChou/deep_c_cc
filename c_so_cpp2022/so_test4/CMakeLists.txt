cmake_minimum_required(VERSION 3.10)
project(DLDEMO)
add_subdirectory(src)
include_directories(include)
add_executable(${PROJECT_NAME} main.cc)
target_link_libraries(${PROJECT_NAME} dl)

