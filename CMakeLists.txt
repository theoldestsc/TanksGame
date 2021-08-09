cmake_minimum_required(VERSION 3.0.0)
project(Tanks VERSION 0.1.0)



option(ENABLE_UNIT_TESTS "Enable unittest" ON)
message(STATUS "Enable testing: ${ENABLE_UNIT_TESTS}")
if(ENABLE_UNIT_TESTS)
	message(STATUS "Compiling tests ...")
	enable_testing()
	add_executable(
	  hello_test
	  tests/hello_test.cpp
	)
	target_link_libraries(
	  hello_test
	  gtest
	  pthread
	  gtest_main
	)
	include(GoogleTest)
	gtest_discover_tests(hello_test)
endif()

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
if(NOT SDL2_IMAGE_FOUND)
	message(FATAL_ERROR "SDL2_IMAGE NOT FOUND")
	return()
endif()
if(NOT SDL2_FOUND)
	message(FATAL_ERROR "SDL2 NOT FOUND")
	return()
else()
	add_compile_options("-g"
						"-Wall"
						"$<$<CONFIG:DEBUG>:-O0;-g3;-ggdb>")
	include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} headers/)

    file(GLOB SOURCES "src/*.cpp")

	add_executable(main ${SOURCES})
	message(${CMAKE_CURRENT_SOURCE_DIR})
	target_link_libraries(main ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
	file(COPY Sprites DESTINATION .)
endif()

