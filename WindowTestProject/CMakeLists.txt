
cmake_minimum_required (VERSION 3.22.1)
project (WindowTestProject
	VERSION 0.1.0
	DESCRIPTION "placeholder description"
)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(libs/glfw-3.4)
add_subdirectory(libs/WindowTest)
