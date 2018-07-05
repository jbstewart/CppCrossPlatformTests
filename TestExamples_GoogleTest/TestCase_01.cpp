#include "gtest/gtest.h"
#include "gmock/gmock.h" 
#include <iostream>

using ::testing::Return;

class Interface {
public:
	virtual ~Interface() {}
	virtual void DoThingA() = 0;
	virtual int DoThingB() = 0;
	virtual std::string GetPropC() = 0;
	virtual void SetPropC(std::string val) = 0;
};

class RealClass : public Interface {
public:
	virtual void DoThingA() {
		std::cout << "ThingA";
	}

	virtual int DoThingB() {
		std::cout << "ThingA";
	}

	virtual std::string GetPropC() {
		return _propC;
	}

	virtual void SetPropC(std::string val) {
		_propC = val;
	}

private:
	std::string _propC;

};

class Mock : public Interface {
public:
	virtual ~Mock() {}
	
	MOCK_METHOD0(DoThingA, void());
	MOCK_METHOD0(DoThingB, int());
	MOCK_METHOD0(GetPropC, std::string());
	MOCK_METHOD1(SetPropC, void(std::string val));
};

class SystemUnderTest {
public:
	SystemUnderTest(Interface& theClass) : _theClass(theClass) {}

	std::string Act() {
		_theClass.SetPropC("foo");
		if (_theClass.DoThingB() < 5) {
			_theClass.DoThingA();
			_theClass.SetPropC("farkle");
		}
		return _theClass.GetPropC();
	}

private:
	Interface& _theClass;
};

TEST(TestCase01, MyTest01) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

TEST(TestCase01, MyTest02) {
	EXPECT_EQ(1, 0);
	EXPECT_TRUE(true);
}

TEST(TestCase01, SUT_ThingBLessThanFive) {
	Mock myMock;
	EXPECT_CALL(myMock, DoThingB()).Times(1).WillOnce(Return(3));
	EXPECT_CALL(myMock, DoThingA()).Times(1);
	EXPECT_CALL(myMock, SetPropC("foo")).Times(1);
	EXPECT_CALL(myMock, SetPropC("farkle")).Times(1);
	EXPECT_CALL(myMock, GetPropC()).Times(1).WillOnce(Return("farkle"));
	SystemUnderTest sut(myMock);
	EXPECT_EQ(sut.Act(), "farkle");
}

TEST(TestCase01, SUT_ThingBEqualToFive) {
	Mock myMock;
	EXPECT_CALL(myMock, DoThingB()).Times(1).WillOnce(Return(5));
	EXPECT_CALL(myMock, DoThingA()).Times(0);
	EXPECT_CALL(myMock, SetPropC("foo")).Times(1);
	EXPECT_CALL(myMock, SetPropC("farkle")).Times(0);
	EXPECT_CALL(myMock, GetPropC()).Times(1).WillOnce(Return("foo"));
	SystemUnderTest sut(myMock);
	EXPECT_EQ(sut.Act(), "foo");
}

TEST(TestCase01, SUT_ThingBGreaterThanFive) {
	Mock myMock;
	EXPECT_CALL(myMock, DoThingB()).Times(1).WillOnce(Return(5));
	EXPECT_CALL(myMock, DoThingA()).Times(0);
	EXPECT_CALL(myMock, SetPropC("foo")).Times(1);
	EXPECT_CALL(myMock, SetPropC("farkle")).Times(0);
	EXPECT_CALL(myMock, GetPropC()).Times(1).WillOnce(Return("foo"));
	SystemUnderTest sut(myMock);
	EXPECT_EQ(sut.Act(), "foo");
}
