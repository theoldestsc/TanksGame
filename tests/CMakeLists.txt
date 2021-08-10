cmake_minimum_required(VERSION 3.0.0)
project(Tests VERSION 0.1.0)


message(STATUS "Compiling tests ...")
enable_testing()

file(GLOB TEST_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}  "*.cpp")
include_directories(${SDL2_INCLUDE_DIRS} 
                    ${SDL2_IMAGE_INCLUDE_DIRS}
                    "../headers/")
foreach(TEST_SRC_NAME ${TEST_SOURCES})
    get_filename_component(EXECUTABLE_NAME 
                           ${TEST_SRC_NAME} 
                           NAME_WE)
    add_executable(${EXECUTABLE_NAME} ${TEST_SRC_NAME})
    target_link_libraries(${EXECUTABLE_NAME}
                          gtest
                          pthread
                          gtest_main
                          ${SDL2_LIBRARIES} 
                          ${SDL2_IMAGE_LIBRARIES} 
                          )
    add_test(NAME ${EXECUTABLE_NAME}
             WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
             COMMAND ${EXECUTABLE_NAME})
endforeach(TEST_SRC_NAME ${TEST_SOURCES})
include(GoogleTest)

add_custom_target(check 
                  COMMAND /usr/bin/./make -j4
                  COMMAND ${CMAKE_CTEST_COMMAND}
                  ) #TODO: fix DEPENDS
