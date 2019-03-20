cmake_minimum_required(VERSION 3.8.0 FATAL_ERROR)

include_directories(
    .
    )


add_library(my_copyif
    my_copyif.h
    my_copyif.cpp
    )

add_executable(main
    main.cpp
    )

target_link_libraries(main
    my_copyif
    )
