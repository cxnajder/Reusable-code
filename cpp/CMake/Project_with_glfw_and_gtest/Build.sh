#!/bin/sh
cmake -D GLFW_BUILD_DOCS=OFF -S Source -B Build
make -C Build