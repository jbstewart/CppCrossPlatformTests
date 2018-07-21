#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include<Catch.hpp>

TEST_CASE("Catch_PASS") {
	REQUIRE(0 == 0);
}

TEST_CASE("Catch_FAIL") {
	REQUIRE(0 == 1);
}

TEST_CASE("Section Tests") {

	SECTION("Section_Catch_PASS") {
		REQUIRE(0 == 0);
	}

	SECTION("Section_Catch_FAIL") {
		REQUIRE(0 == 1);
	}
}
