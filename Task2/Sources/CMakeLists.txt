cmake_minimum_required(VERSION 3.20)
project(abc2)

set(CMAKE_CXX_STANDARD 14)

add_executable(abc2 main.cpp Shapes.cpp Shapes.h Shape.cpp Shape.h Sphere.cpp Sphere.h Parallelepiped.cpp Parallelepiped.h RightTetrahedron.cpp RightTetrahedron.h Randomize.h)
