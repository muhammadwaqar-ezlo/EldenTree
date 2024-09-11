# Elden Tree Event Handler

## Overview

The Elden Tree is an event handler system designed for high performance and modularity. It provides a mechanism to manage and dispatch events associated with different gods in a flexible and efficient manner. The event handler is implemented in C++ and provides a clean API for registering and handling events.

## Project Structure


- **`event_handler/`**: Contains the implementation of the `EventHandler` class.
- **`benchmarks/`**: Contains the benchmark code to measure the performance of the event handler.
- **`tests/`**: Contains the test cases to verify the correctness of the event handler.
- **`scripts/`**: Contains scripts for code formatting and style checks.
- **`main.cpp`**: Contains the main entry point for the application.

## Dependencies

- CMake (version 3.2 or higher)
- Google Test (gtest) for unit testing
- Google Benchmark for performance benchmarking
- Clang-Format for code formating


## Prerequisites

Make sure you have CMake, Google Test and Google Benchmark installed. On Ubuntu, you can install them using:

```bash
sudo apt-get install cmake libgtest-dev libbenchmark-dev
```
## Run Code Style Formatter

You could build pretty target for auto-formatting code. But You need to install clang-format 6 for correct working of it. Example for Ubuntu:

```
    sudo apt-get install clang-format-6.0
    sudo ln -s /usr/bin/clang-format-6.0 /usr/bin/clang-format
```

Move to <SOURCES>/build/ folder and run:

    make format

Code should be changed according current code style.

**Note:** If you encounter a permission error, give the format script execution permission by running:
```
    sudo chmod +x /path/to/your/clone/EldenTree/scripts/format_code.sh
```

## Build Steps

### 1. Clone the repository:

```
    git@github.com:muhammadwaqar-ezlo/EldenTree.git
    cd EldenTree
```

### 2. Create and navigate to the build directory:

```
    mkdir build
    cd build
```

### 3. Run CMake:

```
    cmake ..
```

### 4. Build the project:

```
    make
```

## Running Benchmarks

```
    ./benchmark/benchmark_program
```

## Running Main Program

```
    ./main_program
```

## Running Tests

```
    ./tests/test_program
```

