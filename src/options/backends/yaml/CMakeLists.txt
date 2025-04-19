if(OPTIONS_WITH_YAML)
    message(STATUS "Building YAML backend")

    add_library(backend_yaml foo.cpp)
    target_link_libraries(backend_yaml yaml-cpp)
endif()
