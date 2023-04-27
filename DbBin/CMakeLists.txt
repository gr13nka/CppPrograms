cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(db)

set(CMAKE_CXX_STANDARD 17)
add_executable(db main.cpp record.cpp Database.cpp interface.cpp record.h Database.h  interface.h)

