cmake_minimum_required(VERSION 3.0.0)
project(Tanks VERSION 0.1.0)

option(ENABLE_UNIT_TESTS "Enable unittest" ON)
message(STATUS "Enable testing: ${ENABLE_UNIT_TESTS}")

if(ENABLE_UNIT_TESTS)
	add_subdirectory(tests)
endif()


list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)
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
	
	include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} headers/)
    file(GLOB SOURCES "src/*.cpp")
	add_executable(main ${SOURCES})
	set_target_properties(main
	  					  PROPERTIES
						  ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
						  LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
						  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
						  CMAKE_CXX_STANDARD_REQUIRED ON
						  CMAKE_CXX_STANDARD 17
						  CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++17"
						  CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -g"
						  CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O2"
						 )
	target_link_libraries(main 
						  ${SDL2_LIBRARIES} 
						  ${SDL2_IMAGE_LIBRARIES})
	message(STATUS "Copy sprites folder")
	file(COPY Sprites DESTINATION .)
endif()

