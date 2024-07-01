@echo on
cmake -D GLFW_BUILD_DOCS=OFF -S Source -B Build
ninja -C Build