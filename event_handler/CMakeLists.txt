# Event handler library
add_library(event_handler SHARED event_handler.cpp)

# Include directory for the library
target_include_directories(event_handler PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})