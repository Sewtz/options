add_executable(test_core tests_core.cpp)

target_link_libraries(test_core
    PRIVATE
        core
        GTest::gtest
        GTest::gtest_main
)

target_include_directories(test_core
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

add_test(NAME CoreTests COMMAND test_core)