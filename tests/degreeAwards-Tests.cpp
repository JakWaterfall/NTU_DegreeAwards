#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE DegreeAwardsTests
#include <boost/test/unit_test.hpp>

#include "degreeAwards.h"

/////////////////////////////////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_CASE( Mean )
{
    degreeAwards award;
    BOOST_CHECK_EQUAL( award.getMean({"High 1st", "Mid 1st", "High 2:2"}) , 12.6 );
}

BOOST_AUTO_TEST_CASE( MajorityGrade )
{
    degreeAwards award;
    BOOST_CHECK_EQUAL( award.getMajorityGrade({"High 1st", "Mid 1st", "High 2:2"}) , "1st" );
}

BOOST_AUTO_TEST_CASE( StubTest )
{
    BOOST_CHECK_EQUAL( 0 , 0 );
}

/////////////////////////////////////////////////////////////////////////////////////////
