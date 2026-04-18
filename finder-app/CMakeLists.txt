cmake_minimum_required(VERSION 3.10)

# 1. Handle the CROSS_COMPILE variable from the command line or environment
if(NOT DEFINED CROSS_COMPILE AND DEFINED ENV{CROSS_COMPILE})
    set(CROSS_COMPILE $ENV{CROSS_COMPILE})
endif()

# 2. If CROSS_COMPILE is set, tell CMake to use that compiler
if(CROSS_COMPILE)
    set(CMAKE_C_COMPILER ${CROSS_COMPILE}gcc)
    # Optional: Tell CMake we are cross-compiling so it doesn't try to run the binaries
    set(CMAKE_SYSTEM_NAME Linux)
    set(CMAKE_SYSTEM_PROCESSOR aarch64)
endif()

project(WriterProject C)

# 3. Ensure the output binary 'writer' is in the source directory (as expected by the grader)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIRECTORY})

add_executable(writer writer.c)
target_compile_options(writer PRIVATE -Wall -Werror)