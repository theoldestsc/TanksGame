cmake_minimum_required(VERSION 3.16.3)
project(Tanks VERSION 0.1.0)

option(ENABLE_UNIT_TESTS "Enable unittest" OFF)
option(ENABLE_SANITIZER "Pass -fsanitize=address and -fsanitize=leak to compiller" OFF)
message(STATUS "Enable testing: ${ENABLE_UNIT_TESTS}")
message(STATUS "Enable sanitizer: ${ENABLE_SANITIZER}")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} headers/)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
string(APPEND CMAKE_CXX_FLAGS " -Wall -Wextra -pedantic")

if(ENABLE_SANITIZER) 
  string(APPEND CMAKE_CXX_FLAGS " -fsanitize=address -fsanitize=leak")
  string(APPEND CMAKE_LINKER_FLAGS " -fsanitize=address -fsanitize=leak")
endif()

#		/*Bad practice but if comfortbale uncomment line below and comment set(SOURCES ...*\
#file(GLOB SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/*.cpp")

set(SOURCES "src/Bullet.cpp"
			"src/Game.cpp"
			"src/GameStateMachine.cpp"
			"src/InputManager.cpp"
			"src/LoaderParams.cpp"
			"src/MenuButton.cpp"
			"src/MenuState.cpp"
			"src/PlayState.cpp"
			"src/SDLGameObject.cpp"
			"src/Tank.cpp"
			"src/TextureManager.cpp"
			"src/Vector2D.cpp"
			"src/main.cpp")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

add_executable(main ${SOURCES})

target_compile_options(main PUBLIC ${CMAKE_CXX_FLAGS_DEBUG})
target_link_libraries(main 
					  ${SDL2_LIBRARIES} 
					  ${SDL2_IMAGE_LIBRARIES})
message(STATUS "Copy sprites folder into build dir")
file(COPY Sprites DESTINATION .)
if(ENABLE_UNIT_TESTS)	
	enable_testing()
	add_subdirectory(tests)
endif()