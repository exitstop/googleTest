cmake_minimum_required(VERSION 3.8.0 FATAL_ERROR)

# anti pattern cmake
# include_directories(.)

# anti pattern cmake
#file(GLOB MY_COPYIF_SRC "my_copyif.*")

add_library(my_copyif
    #"${MY_COPYIF_SRC}" # anti pattern cmake
    my_copyif.h
    my_copyif.cpp
    )

target_include_directories(my_copyif PRIVATE 
    .)

add_executable(main
    main.cpp
    )

target_include_directories(main PRIVATE 
    .)

target_link_libraries(main
    my_copyif
    )
