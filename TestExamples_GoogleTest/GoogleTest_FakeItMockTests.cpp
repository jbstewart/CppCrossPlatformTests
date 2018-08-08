#include "gtest/gtest.h"

#include "SimpleExampleSUT.h"

#ifndef INTEL_CXX
#include <fakeit.hpp>
using namespace fakeit;

TEST(GoogleTestFakeItMockTests, ThingBLessThanFive) {
	Mock<Interface> mock;
	Fake(Method(mock, DoThingA));
	When(Method(mock, DoThingB)).Return(3);
	When(Method(mock, GetPropC)).Return("farkle");
	Fake(Method(mock, SetPropC));
	SystemUnderTest sut(mock.get());
	EXPECT_EQ(sut.Act(), "farkle");

	Verify(Method(mock, DoThingA)).Once();
	Verify(Method(mock, DoThingB)).Once();
	Verify(Method(mock, SetPropC).Using("foo")).Once();
	Verify(Method(mock, SetPropC).Using("farkle")).Once();
}

TEST(GoogleTestFakeItMockTests, ThingBEqualToFive) {
	Mock<Interface> mock;
	Fake(Method(mock, DoThingA), Method(mock, SetPropC));
	When(Method(mock, DoThingB)).Return(5);
	When(Method(mock, GetPropC)).Return("foo");
	SystemUnderTest sut(mock.get());
	EXPECT_EQ(sut.Act(), "foo");

	Verify(Method(mock, DoThingA)).Never();
	Verify(Method(mock, DoThingB)).Once();
	Verify(Method(mock, SetPropC).Using("foo")).Once();
	Verify(Method(mock, SetPropC).Using("farkle")).Never();
}

TEST(GoogleTestFakeItMockTests, ThingBGreaterThanFive) {
	Mock<Interface> mock;
	Fake(Method(mock, DoThingA), Method(mock, SetPropC));
	When(Method(mock, DoThingB)).Return(6);
	When(Method(mock, GetPropC)).Return("foo");
	SystemUnderTest sut(mock.get());
	EXPECT_EQ(sut.Act(), "foo");

	Verify(Method(mock, DoThingA)).Never();
	Verify(Method(mock, DoThingB)).Once();
	Verify(Method(mock, SetPropC).Using("foo")).Once();
	VerifyNoOtherInvocations(Method(mock, SetPropC));
}
#endif
