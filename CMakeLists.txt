cmake_minimum_required(VERSION 3.2)

# Project name
project(EldenTree LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch GoogleTest
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.11.0
)
FetchContent_MakeAvailable(googletest)

# Add subdirectories
add_subdirectory(event_handler)  # Add the event handler library
add_subdirectory(benchmark)     # Add the benchmark executable
add_subdirectory(tests)          # Add the test executable

# Find the PThreads library
find_package(Threads REQUIRED)

# Main executable
add_executable(main_program main.cpp)

# Link the main program with the event handler library
target_link_libraries(main_program PRIVATE event_handler ${CMAKE_THREAD_LIBS_INIT})

# Set include directories for main
target_include_directories(main_program PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/event_handler)

# Custom target for code formatting
add_custom_target(
        format
        COMMAND ${CMAKE_COMMAND} -E env "PATH=$ENV{PATH}" bash ${CMAKE_SOURCE_DIR}/scripts/format_code.sh
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Formatting all source files with clang-format"
)

