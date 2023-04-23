cmake_minimum_required(VERSION 3.5)

project(SFINAE)

add_executable(sfinae sfinae.cpp)
set_target_properties(sfinae PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)