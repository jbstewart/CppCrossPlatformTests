// Link to Boost
//#define BOOST_TEST_DYN_LINK

// Define the module name for this test module
#define BOOST_TEST_MODULE "BoostTestSimpleExamples"

// VERY IMPORTANT - include this last
 #include <boost/test/unit_test.hpp>
//#include <test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(PassingBoostTest)
{
	BOOST_CHECK(0 == 0);
}

BOOST_AUTO_TEST_CASE(FailingBoostTest)
{
	BOOST_CHECK(1 == 0);
}
