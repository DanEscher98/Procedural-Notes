#include <gtest/gtest.h>
#include "utils.hpp"

TEST(ExampleTest, Addition) {
  EXPECT_EQ(2 + 2, 4);
}

TEST(MockTest, Mock) {
  EXPECT_EQ(mock(2), 4);
}
