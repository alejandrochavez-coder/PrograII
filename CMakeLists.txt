cmake_minimum_required(VERSION 3.10)
project(InverseKinematics)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(InverseKinematics
    main.cpp
    vector2d.h
    inverse_kinematics.cpp
    inverse_kinematics.hpp
    dynamic_array.h
    canvas.hpp
    canvas.cpp
    dynamics.hpp
)
