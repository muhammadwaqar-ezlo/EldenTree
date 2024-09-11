# Enable testing for CTest
enable_testing()

# Test executable
add_executable(test_program event_handler_test.cpp)

# Link the test executable with the event handler library and GTest
target_link_libraries(test_program PRIVATE event_handler gtest gtest_main)

# Include directories for tests
target_include_directories(test_program PRIVATE ${CMAKE_SOURCE_DIR}/event_handler)

# Add tests to CTest
add_test(NAME EventHandlerTests COMMAND test_program)

