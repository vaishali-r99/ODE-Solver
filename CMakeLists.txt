cmake_minimum_required(VERSION 3.1)
project(ODESOLVER VERSION 0.1.0 LANGUAGES CXX)
add_executable(ODESOLVER main.cpp scheme.cpp ExplicitEuler.cpp ImplicitEuler.cpp newton.cpp f.cpp)
