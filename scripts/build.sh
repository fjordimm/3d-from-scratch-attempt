cd ./WindowTestProject/build/
cmake .. -D GLFW_BUILD_WAYLAND=0
cmake --build .
cd ../..