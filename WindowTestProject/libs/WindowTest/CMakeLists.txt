
add_executable(MamaMia
	src/WindowTest/main.cpp
)

target_include_directories(MamaMia PUBLIC include)

find_package(GLEW REQUIRED)
target_link_libraries(MamaMia GLEW::glew)
target_link_libraries(MamaMia glfw)
find_package(OpenGL REQUIRED)
target_link_libraries(MamaMia OpenGL::GL)

# target_compile_features(MamaMia PUBLIC cxx_std_20)
