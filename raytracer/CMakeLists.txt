cmake_minimum_required(VERSION 3.9)

project(render)

add_executable(
    render main.cc color.hpp ray.hpp vec3.hpp
)