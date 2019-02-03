from https://radicalrafi.github.io/posts/pytorch-cpp-intro/


Compiling:
-----------------------------------------------

1. First create a CMakeLists.txt in your directory
2. Next save the code in a C++ File --> first_example.cc
3. Create a “build” folder

At this point your directory should look like this

├── CMakeLists.txt
├── first_example.cc
└── build

── CMakeLists.txt contents ──
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(first_example)

find_package(Torch REQUIRED)

add_executable(first_example first_example.cpp)
target_link_libraries(first_example "${TORCH_LIBRARIES}")
set_property(TARGET first_example PROPERTY CXX_STANDARD 11)
──

4. cd build

5. cmake -DCMAKE_PREFIX_PATH=~/libtorch ..

5.b Debug build:

cmake -DCMAKE_PREFIX_PATH=~/libtorch -DCMAKE_BUILD_TYPE=Debug ..


6. make 

Running:
-----------------------------------------------
./first_example
