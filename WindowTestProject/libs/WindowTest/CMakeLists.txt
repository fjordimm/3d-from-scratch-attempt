add_executable(MamaMia
	src/WindowTest/main.cpp
	src/WindowTest/Man.cpp
)
target_compile_features(MamaMia PUBLIC cxx_std_20)
target_include_directories(MamaMia PUBLIC include)