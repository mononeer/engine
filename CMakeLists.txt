# Set the minimum required version of CMake for C++20 support
cmake_minimum_required(VERSION 3.20)

# Define the project name, version, and language
project(RevoltEngine VERSION 0.1.0 LANGUAGES CXX)

# Set the C++ standard to C++20 and enforce it
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# --- Dependencies ---
# Use FetchContent to manage external libraries at configure time
include(FetchContent)

# spdlog - Fast C++ logging library
FetchContent_Declare(
  spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog.git
  GIT_TAG        v1.14.1 # A recent stable version
)
# Make the dependency available to the project
FetchContent_MakeAvailable(spdlog)


# Add the primary subdirectories to the build configuration
add_subdirectory(revolt)
add_subdirectory(modules)
add_subdirectory(tools)
add_subdirectory(tests)

# Provide feedback to the user during configuration
message(STATUS "Project Name: ${PROJECT_NAME}")
message(STATUS "Project Version: ${PROJECT_VERSION}")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
