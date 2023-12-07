cmake_minimum_required(VERSION 3.16)

find_package(Catch2 2 REQUIRED)

add_executable(potion potion_test.cpp)
target_link_libraries(potion objects Catch2::Catch2)