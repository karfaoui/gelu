cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

# The project name
project(gelu_cpp)

find_package(Torch REQUIRED)

# some more setup
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

# The sources shared between the main program and the tests
set (PROJECT_SOURCES src/Activation.cpp src/FileUtils.cpp)


# The main program
add_executable(${PROJECT_NAME} src/main.cpp ${PROJECT_SOURCES})

# The tests
# add_executable(tests testmain.cpp ${PROJECT_SOURCES})

# other
target_link_libraries(${PROJECT_NAME} "${TORCH_LIBRARIES}")
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)
