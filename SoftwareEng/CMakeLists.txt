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
        Main_Directory/main.cpp
        xmlparser/tinyxml.cpp
        xmlparser/tinyxmlerror.cpp
        xmlparser/tinystr.cpp
        xmlparser/tinyxmlparser.cpp
        Main_Directory/System.cpp
        Main_Directory/Room.cpp
        Main_Directory/Participation.cpp
        Main_Directory/Meeting.cpp)
# Set source files for DEBUG target
# Only add cpp files, no h files!
# Make sure the "main" function is in "main_debug"!
set(DEBUG_SOURCE_FILES
        src/DesignByContract.h
        Tests/Tests.cpp
        Main_Directory/System.cpp
        xmlparser/tinystr.cpp
        xmlparser/tinyxmlerror.cpp
        xmlparser/tinyxmlparser.cpp
        xmlparser/tinyxml.cpp
        Main_Directory/System.cpp
        Main_Directory/Room.cpp
        Main_Directory/Participation.cpp
        Main_Directory/Meeting.cpp

)
# Create RELEASE target
add_executable(release_target ${RELEASE_SOURCE_FILES}
        Main_Directory/main.cpp
)
# Create DEBUG target
add_executable(debug_target ${DEBUG_SOURCE_FILES}

        Tests/Tests.cpp




)
# Link library
target_link_libraries(debug_target gtest)