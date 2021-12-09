cmake_minimum_required(VERSION 3.1)
project(Code VERSION 0.1.0 LANGUAGES CXX )
add_executable(main main.cpp exp_euler.cpp analytical_soln.cpp)
add_executable(test test.cpp)
