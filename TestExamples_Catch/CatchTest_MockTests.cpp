#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include<Catch.hpp>
#include <fakeit.hpp>
#include "SimpleExampleInterface.h"
#include "SimpleExampleSUT.h"

using namespace fakeit;


TEST_CASE("Catch_Mock01") {
	Mock<Interface> mock;
	Fake(Method(mock, DoThingA));
	When(Method(mock, DoThingB)).Return(3);
	When(Method(mock, GetPropC)).Return("farkle");
	Fake(Method(mock, SetPropC));
	SystemUnderTest sut(mock.get());
	REQUIRE(sut.Act() == "farkle");

	Verify(Method(mock, DoThingA)).Once();
	Verify(Method(mock, DoThingB)).Once();
	Verify(Method(mock, SetPropC).Using("foo")).Once();
	Verify(Method(mock, SetPropC).Using("farkle")).Once();
}

TEST_CASE("Catch_Mock02") {
	REQUIRE(false);
}

TEST_CASE("Catch_Mock03") {
	REQUIRE(false);
}
