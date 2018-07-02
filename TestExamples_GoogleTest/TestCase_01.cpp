#include "gtest/gtest.h"

TEST(TestCase01, MyTest01) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

TEST(TestCase01, MyTest02) {
	EXPECT_EQ(1, 0);
	EXPECT_TRUE(true);
}
