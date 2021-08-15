cmake_minimum_required(VERSION 3.0.0)
project(Tests VERSION 0.1.0)


message(STATUS "Compiling tests ...")

file(GLOB TEST_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}  "*.cpp")

include_directories(${SDL2_INCLUDE_DIRS} 
                    ${SDL2_IMAGE_INCLUDE_DIRS}
                    "../headers/")
add_library(Vector2D
            STATIC
            "../headers/Vector2D.h"
            "../src/Vector2D.cpp"
            )
foreach(TEST_SRC_NAME ${TEST_SOURCES})
    get_filename_component(EXECUTABLE_NAME 
                           ${TEST_SRC_NAME} 
                           NAME_WE)
    add_executable(${EXECUTABLE_NAME} ${TEST_SRC_NAME})
    
    target_link_libraries(${EXECUTABLE_NAME}
                          gtest
                          pthread
                          gtest_main
                          Vector2D
                          ${SDL2_LIBRARIES} 
                          ${SDL2_IMAGE_LIBRARIES}
                          )
    add_test(NAME ${EXECUTABLE_NAME}     
             COMMAND ${EXECUTABLE_NAME})
endforeach(TEST_SRC_NAME ${TEST_SOURCES})
include(GoogleTest)
                  