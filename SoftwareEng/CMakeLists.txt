cmake_minimum_required(VERSION 3.10)
project(SoftwareEng)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 17)
# Remove the "-O2" flag if you have problems with the debugger.
set(CMAKE_CXX_FLAGS "-std=c++17 -Wall")
set(CMAKE_EXE_LINKER_FLAGS -pthread)
# Set include dir
include_directories(./gtest/include)
# Set Library dir
link_directories(./gtest/lib)
# Set source files for RELEASE target
# Only add cpp files, no h files!
# Only add files with functionality here, no test files!
# Make sure the "main" function is in "main_release"!
set(RELEASE_SOURCE_FILES
        "Main Directory/main.cpp")
# Set source files for DEBUG target
# Only add cpp files, no h files!
# Make sure the "main" function is in "main_debug"!
set(DEBUG_SOURCE_FILES "Main Directory/main.cpp"
        "Main Directory/Meeting.cpp"
        "Main Directory/Meeting.h"
        "Main Directory/Room.cpp"
        "Main Directory/Room.h"
        "Main Directory/Participation.cpp"
        "Main Directory/Participation.h"
        "Main Directory/Date.cpp"
        "Main Directory/Date.h"
        "Main Directory/System.cpp"
        "Main Directory/System.h")
# Create RELEASE target
add_executable(release_target ${RELEASE_SOURCE_FILES}
        "Main Directory/main.cpp")
# Create DEBUG target
add_executable(debug_target ${DEBUG_SOURCE_FILES}
        "Main Directory/main.cpp")
# Link library
target_link_libraries(debug_target gtest)