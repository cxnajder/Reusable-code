cmake_minimum_required(VERSION 3.10)
project(CMmakeProject VERSION 1.0)

add_subdirectory(External/glfw)
add_subdirectory(External/googletest)

set(GLFW_PROGRAM "glfwApp")
add_executable(${GLFW_PROGRAM} glfwApp/Main.cpp)

target_include_directories(${GLFW_PROGRAM} PUBLIC External/glfw/include)
target_link_libraries(${GLFW_PROGRAM} glfw)


set(BASIC_TESTS_PROGRAM "BasicTests")
add_executable(${BASIC_TESTS_PROGRAM} ${BASIC_TESTS_PROGRAM}/${BASIC_TESTS_PROGRAM}.cpp)

target_include_directories(${BASIC_TESTS_PROGRAM} PUBLIC External/googletest/googletest/include)
target_link_libraries(${BASIC_TESTS_PROGRAM} gtest gtest_main)