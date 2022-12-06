cmake_minimum_required(VERSION 3.16)

set(CMAKE_C_COMPILER "gcc")

project(webgenapp LANGUAGES C)

# Specify the source files for the library that are in the lib directory.
file(GLOB webgenlib_SOURCES "lib/*.c")

# Create a library called webgenlib from the specified source files.
add_library(webgenlib ${webgenlib_SOURCES})

file(GLOB APP_SOURCES "*.c")

# Add the app target.
add_executable(webgenapp ${APP_SOURCES})

# Link the webgenlib library to the app target.
target_link_libraries(webgenapp webgenlib)

install(TARGETS webgenapp DESTINATION bin)