cmake_minimum_required(VERSION 3.10)
project(InverseKinematics)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(InverseKinematics
    main.cpp
    grid.h
    grid.cpp
    cinematica.cpp
    recursion.cpp
    vector2d.h
)
