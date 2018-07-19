#include "gtest/gtest.h"
#include "gmock/gmock.h" 
#include <iostream>

#include "SimpleExampleSUT.h"

using ::testing::Return;

class Mock : public Interface {
public:
	virtual ~Mock() {}

	MOCK_METHOD0(DoThingA, void());
	MOCK_METHOD0(DoThingB, int());
	MOCK_METHOD0(GetPropC, std::string());
	MOCK_METHOD1(SetPropC, void(std::string val));
};

TEST(GoogleTestMockTests, ThingBLessThanFive) {
	Mock myMock;
	EXPECT_CALL(myMock, DoThingB()).Times(1).WillOnce(Return(3));
	EXPECT_CALL(myMock, DoThingA()).Times(1);
	EXPECT_CALL(myMock, SetPropC("foo")).Times(1);
	EXPECT_CALL(myMock, SetPropC("farkle")).Times(1);
	EXPECT_CALL(myMock, GetPropC()).Times(1).WillOnce(Return("farkle"));
	SystemUnderTest sut(myMock);
	EXPECT_EQ(sut.Act(), "farkle");
}

TEST(GoogleTestMockTests, ThingBEqualToFive) {
	Mock myMock;
	EXPECT_CALL(myMock, DoThingB()).Times(1).WillOnce(Return(5));
	EXPECT_CALL(myMock, DoThingA()).Times(0);
	EXPECT_CALL(myMock, SetPropC("foo")).Times(1);
	EXPECT_CALL(myMock, SetPropC("farkle")).Times(0);
	EXPECT_CALL(myMock, GetPropC()).Times(1).WillOnce(Return("foo"));
	SystemUnderTest sut(myMock);
	EXPECT_EQ(sut.Act(), "foo");
}

TEST(GoogleTestMockTests, ThingBGreaterThanFive) {
	Mock myMock;
	EXPECT_CALL(myMock, DoThingB()).Times(1).WillOnce(Return(5));
	EXPECT_CALL(myMock, DoThingA()).Times(0);
	EXPECT_CALL(myMock, SetPropC("foo")).Times(1);
	EXPECT_CALL(myMock, SetPropC("farkle")).Times(0);
	EXPECT_CALL(myMock, GetPropC()).Times(1).WillOnce(Return("foo"));
	SystemUnderTest sut(myMock);
	EXPECT_EQ(sut.Act(), "foo");
}
