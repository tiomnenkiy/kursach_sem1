cmake_minimum_required(VERSION 3.16)
project(kurs)

set(CMAKE_CXX_STANDARD 14)

add_executable(kurs main.cpp employee.h employee.cpp personality.h personality.cpp workshop.cpp workshop.h input.h input.cpp files.cpp files.h menu.cpp menu.h)