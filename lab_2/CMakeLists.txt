cmake_minimum_required(VERSION 3.16)
project(lab_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab_2.1 lab_2.1.cpp)
target_compile_definitions(lab_2.1 PRIVATE L2T1=1)
add_executable(lab_2.2 lab_2.2.cpp)
target_compile_definitions(lab_2.2 PRIVATE L2T2=1)
add_executable(lab_2.3 lab_2.3.cpp)

