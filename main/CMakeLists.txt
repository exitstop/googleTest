cmake_minimum_required(VERSION 3.8.0 FATAL_ERROR)

include_directories(
    .
    )

file(GLOB MY_COPYIF_SRC "my_copyif.*")

add_library(my_copyif
    "${MY_COPYIF_SRC}"
    )

add_executable(main
    main.cpp
    )

target_link_libraries(main
    my_copyif
    )
