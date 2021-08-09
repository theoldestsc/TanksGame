cmake_minimum_required(VERSION 3.0.0)
project(Tests VERSION 0.1.0)


message(STATUS "Compiling tests ...")
enable_testing()
add_executable(
  hello_test
  hello_test.cpp
)
target_link_libraries(
  hello_test
  gtest
  pthread
  gtest_main
)
set_target_properties(hello_test
	  				  PROPERTIES
					  ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/tests/lib"
					  LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/tests/lib"
					  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/tests/bin"
					  CMAKE_CXX_STANDARD_REQUIRED ON
					  CMAKE_CXX_STANDARD 17
					)
include(GoogleTest)
gtest_discover_tests(hello_test)
