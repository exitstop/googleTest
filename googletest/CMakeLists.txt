cmake_minimum_required(VERSION 3.8.0 FATAL_ERROR)

include(External_GTest.cmake)

message(STATUS ${GTEST_ROOT})
message(STATUS ${GTEST_INCLUDE_DIR})
message(STATUS ${OPENSSL_ROOT_DIR})

enable_testing()

add_executable(mytest
        gtest_main.cc
        gtest-all.cc
        first_test.cpp
    )

target_include_directories(mytest PRIVATE 
      ../
      ../main
      ${EXT_GTEST_PATH}/src/googletest/googletest
      ${EXT_GTEST_PATH}/src/googletest/googletest/include
    )


target_link_libraries(mytest 
    ${GTEST_BOTH_LIBRARIES} 
    ${CMAKE_THREAD_LIBS_INIT}
    my_copyif
    )
