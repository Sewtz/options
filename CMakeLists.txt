cmake_minimum_required(VERSION 3.14)
project(options LANGUAGES CXX)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Backend options
option(OPTIONS_WITH_YAML "Enable YAML backend" ON)
option(OPTIONS_WITH_JSON "Enable JSON backend" ON)
option(BUILD_TESTS "Build tests" ON)

# Dependencies
set(FETCHCONTENT_BASE_DIR ${CMAKE_BINARY_DIR}/third_party)
include(FetchContent)

# YAML
option(DOWNLOAD_YAML_CPP "Download and use yaml-cpp library" ON)

# Try to find yaml-cpp package
#find_package(yaml-cpp QUIET)

# If yaml-cpp is not found, use FetchContent to download it
if(NOT yaml-cpp_FOUND AND OPTIONS_WITH_YAML)
    if(DOWNLOAD_YAML_CPP)
        message(STATUS "Fetching yaml-cpp...")
        FetchContent_Declare(
            yaml-cpp
            GIT_REPOSITORY https://github.com/jbeder/yaml-cpp.git
            GIT_TAG 0.8.0
        )
        FetchContent_MakeAvailable(yaml-cpp)
    endif()
endif()

# JSON
option(DOWNLOAD_NLOHMANN_JSON "Download and use nlohmann/json library" ON)

# Try to find nlohmann/json package
find_package(nlohmann_json CONFIG QUIET)

# If nlohmann/json is not found, use FetchContent to download it
if(NOT nlohmann_json_FOUND AND OPTIONS_WITH_JSON)
    if(DOWNLOAD_NLOHMANN_JSON)
        message(STATUS "Fetching nlohmann/json...")
        FetchContent_Declare(
            nlohmann_json
            GIT_REPOSITORY https://github.com/nlohmann/json.git
            GIT_TAG v3.11.2
        )
        FetchContent_MakeAvailable(nlohmann_json)
    endif()
endif()

# GTEST
option(DOWNLOAD_GTEST "Download and use GTest library" ON)

# Try to find GTest package
find_package(GTest QUIET)

# If GTest is not found, use FetchContent to download it
if(NOT GTest_FOUND AND BUILD_TESTS)
    if(DOWNLOAD_GTEST)
        message(STATUS "Fetching GTest...")
        FetchContent_Declare(
        GTest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
        )
        FetchContent_MakeAvailable(GTest)
    endif()
endif()

# options library sources
add_subdirectory(src)

# tests
if(BUILD_TESTS)
    message(STATUS "Building tests")
    enable_testing()
    add_subdirectory(tests)
endif()