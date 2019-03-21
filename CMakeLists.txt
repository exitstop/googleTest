cmake_minimum_required (VERSION 3.9.0)

set(CMAKE_CXX_STANDARD 14)

find_package (Threads)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

add_subdirectory(main)
add_subdirectory(googletest)
