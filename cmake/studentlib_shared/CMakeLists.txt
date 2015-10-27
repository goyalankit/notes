# cmake --version => 3.3.2
cmake_minimum_required(VERSION 3.3.2)
project(directory_test)

# bring headers to the project
include_directories(include)

# However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")

add_library(teststudent SHARED ${SOURCES})

install(TARGETS teststudent DESTINATION build/)
