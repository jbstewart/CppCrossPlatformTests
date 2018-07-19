// Link to Boost
// Define the module name for this test module
#define BOOST_TEST_MODULE "BoostTestMockingExamples"

// VERY IMPORTANT - include this last
#include <boost/test/unit_test.hpp>
#include <fakeit.hpp>
#include "SimpleExampleInterface.h"
#include "SimpleExampleSUT.h"

using namespace fakeit;

BOOST_AUTO_TEST_SUITE(BoostTestMockTests)
BOOST_AUTO_TEST_CASE(BoostTestMockTests_ThingBLessThanFive)
{
	Mock<Interface> mock;
	Fake(Method(mock, DoThingA));
	When(Method(mock, DoThingB)).Return(3);
	When(Method(mock, GetPropC)).Return("farkle");
	Fake(Method(mock, SetPropC));
	SystemUnderTest sut(mock.get());
	BOOST_ASSERT(sut.Act() == "farkle");

	Verify(Method(mock, DoThingA)).Once();
	Verify(Method(mock, DoThingB)).Once();
	Verify(Method(mock, SetPropC).Using("foo")).Once();
	Verify(Method(mock, SetPropC).Using("farkle")).Once();
}

BOOST_AUTO_TEST_CASE(BoostTestMockTests_ThingBEqualToFive)
{
	Mock<Interface> mock;
	Fake(Method(mock, DoThingA), Method(mock, SetPropC));
	When(Method(mock, DoThingB)).Return(5);
	When(Method(mock, GetPropC)).Return("foo");
	SystemUnderTest sut(mock.get());
	BOOST_ASSERT(sut.Act() == "farkle");

	Verify(Method(mock, DoThingA)).Once();
	Verify(Method(mock, DoThingB)).Once();
	Verify(Method(mock, SetPropC).Using("foo")).Once();
	Verify(Method(mock, SetPropC).Using("farkle")).Once();
}

BOOST_AUTO_TEST_CASE(BoostTestMockTests_ThingBGreaterThanFive)
{
	Mock<Interface> mock;
	Fake(Method(mock, DoThingA), Method(mock, SetPropC));
	When(Method(mock, DoThingB)).Return(6);
	When(Method(mock, GetPropC)).Return("foo");
	SystemUnderTest sut(mock.get());
	BOOST_ASSERT(sut.Act() == "foo");

	Verify(Method(mock, DoThingA)).Once();
	Verify(Method(mock, DoThingB)).Once();
	Verify(Method(mock, SetPropC).Using("foo")).Once();
	Verify(Method(mock, SetPropC).Using("farkle")).Once();
}

BOOST_AUTO_TEST_SUITE_END()
