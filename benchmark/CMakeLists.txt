# Google Benchmark setup
include(FetchContent)
FetchContent_Declare(
        benchmark
        GIT_REPOSITORY https://github.com/google/benchmark.git
        GIT_TAG v1.7.1
)
FetchContent_MakeAvailable(benchmark)

# Ensure GTest is used in Google Benchmark
option(BENCHMARK_ENABLE_TESTING ON)
option(BENCHMARK_USE_BUNDLED_GTEST OFF)

# Benchmark executable
add_executable(benchmark_program benchmark.cpp)

# Link the benchmark executable with the event handler library and Google Benchmark
target_link_libraries(benchmark_program PRIVATE event_handler benchmark::benchmark)

# Include directories for benchmark
target_include_directories(benchmark_program PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/event_handler)
