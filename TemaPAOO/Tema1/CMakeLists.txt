# CMake version
cmake_minimum_required(VERSION 3.0)


set(projectName "Tema1")
#Project name
project(${projectName})

# Define the search path for header files
include_directories(headere)

# Specify the required C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# Define the executable
add_executable(${PROJECT_NAME}
               headere/EchipaFotbal.hpp
               headere/Barcelona.hpp
               headere/RealMadrid.hpp 
               src/EchipaFotbal.cpp
               src/Barcelona.cpp
               src/RealMadrid.cpp
               src/Main.cpp)