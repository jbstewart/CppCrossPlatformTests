#include "gtest/gtest.h"

// NB: Underscores are not recommended in Google Test test case names or individual test names
// Underscore will likely work, but may break Google Test at some point in the future.

TEST(GoogleTestSimpleTests, PassingTest) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

TEST(GoogleTestSimpleTests, FailingTest) {
	EXPECT_EQ(1, 0);
	EXPECT_TRUE(true);
}
