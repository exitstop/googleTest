cmake_minimum_required (VERSION 3.9.0)
set(CMAKE_CXX_STANDARD 14)

find_package (Threads)

add_subdirectory(main)
add_subdirectory(googletest)
