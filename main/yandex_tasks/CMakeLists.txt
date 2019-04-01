cmake_minimum_required(VERSION 3.8.0 FATAL_ERROR)

# STATIC | SHARED
add_library(ya0 STATIC
    ya0.hpp
    ya0.cpp
    )

target_include_directories(ya0 PRIVATE 
    .)

configure_file("in.txt" "../in.txt" COPYONLY)
configure_file("in.txt" "../../in.txt" COPYONLY)
