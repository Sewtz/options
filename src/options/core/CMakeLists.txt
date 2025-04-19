message(STATUS "Building core library")

set(LIB_CORE_SOURCES
    Options.cpp
    OptionNode.cpp
    OptionValueNode.cpp
)

add_library(core ${LIB_CORE_SOURCES})
target_include_directories(core
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${PROJECT_SOURCE_DIR}/include
)