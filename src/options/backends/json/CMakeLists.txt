if(OPTIONS_WITH_JSON)
    message(STATUS "Building JSON backend")

    add_library(backend_json foo.cpp)
    target_link_libraries(backend_json nlohmann_json::nlohmann_json)
endif()
