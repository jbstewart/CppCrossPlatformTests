// Link to Boost
// Define the module name for this test module
#define BOOST_TEST_MODULE "BoostTestSimpleExamples"

// VERY IMPORTANT - include this last
 #include <boost/test/unit_test.hpp>
//#include <test/included/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(BoostTestSimpleTests)

BOOST_AUTO_TEST_CASE(BoostTestSimpleTests_PassingTest)
{
	BOOST_CHECK(0 == 0);
}

BOOST_AUTO_TEST_CASE(BoostTestSimpleTests_FailingTest)
{
	BOOST_CHECK(1 == 0);
}

BOOST_AUTO_TEST_SUITE_END()
