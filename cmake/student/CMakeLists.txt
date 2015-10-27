# cmake --version => 3.3.2
cmake_minimum_required(VERSION 3.3.2)
project(directory_test)

# bring headers to the project
include_directories(include)

# Can manually add sources using the set comand as follows
# set(SOURCES src/mainapp.cpp src/Student.cpp)

# However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")

add_executable(teststudent ${SOURCES})
