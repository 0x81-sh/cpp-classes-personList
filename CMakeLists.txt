cmake_minimum_required(VERSION 3.21)
project(personList)

set(CMAKE_CXX_STANDARD 23)

add_executable(personList main.cpp Address.cpp Address.h Person.cpp Person.h PersonList.cpp PersonList.h)
