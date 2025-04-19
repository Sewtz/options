#include <gtest/gtest.h>

#include <options/core/Options.hpp>

// Dummy fixture if needed
class OptionsCoreTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Code here will be called before each test
    }

    void TearDown() override {
        // Code here will be called after each test
    }
};

TEST_F(OptionsCoreTest, CreateOptions) {
    EXPECT_NO_THROW({
        options::Options opt;
    });
}