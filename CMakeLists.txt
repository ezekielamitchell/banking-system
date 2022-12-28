cmake_minimum_required(VERSION 3.23)
project(banking_system)

set(CMAKE_CXX_STANDARD 20)

add_executable(banking_system src/main/cpp/main.cpp src/main/cpp/user/User.cpp src/main/cpp/user/User.h src/main/cpp/menu/Menu.h)
