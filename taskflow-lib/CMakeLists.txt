cmake_minimum_required(VERSION 3.10)
project(taskflow_test)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable debug build
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")

# Find taskflow
set(TASKFLOW_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/../") # Adjust this path as needed

# Add library
add_library(taskflow_lib STATIC lib.cpp)
target_include_directories(taskflow_lib 
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${TASKFLOW_INCLUDE_DIR}
)

# Add executable
add_executable(test_taskflow test.cpp)
target_link_libraries(test_taskflow PRIVATE taskflow_lib)

# Add pthread for Linux
if(UNIX AND NOT APPLE)
    target_link_libraries(taskflow_lib PRIVATE pthread)
    target_link_libraries(test_taskflow PRIVATE pthread)
endif()