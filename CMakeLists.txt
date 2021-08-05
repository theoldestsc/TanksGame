cmake_minimum_required(VERSION 3.0.0)
project(Tanks VERSION 0.1.0)

#include(CTest)
#enable_testing()
#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)

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
endif()

