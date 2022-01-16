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
    BOOST_CHECK_EQUAL( award.getMajority({"Low 1st", "Mid 1st", "High 2:2"}) , "Zero" );
    BOOST_CHECK_EQUAL( award.getMajority({"High 1st", "High 1st", "High 2:2"}) , "High 1st" );
    BOOST_CHECK_EQUAL( award.getMajority({"High 1st", "High 1st", "High 1st"}) , "High 1st" );
}

BOOST_AUTO_TEST_CASE( FinalYearGrade )
{
    degreeAwards award;
    std::vector<std::string> finalYearGrades = {"High 1st", "Mid 1st", "High 2:2"};
    BOOST_CHECK_EQUAL( award.getFinalYearGrade({"High 1st", "Mid 1st", "High 2:2"}, finalYearGrades) , 12.6 );
}


BOOST_AUTO_TEST_CASE( GradeFromRatio )
{
    degreeAwards award;
    BOOST_CHECK_EQUAL( award.getGradeFromRatio(12.5) , "1st" );
    BOOST_CHECK_EQUAL( award.getGradeFromRatio(16) , "1st" );
    BOOST_CHECK_EQUAL( award.getGradeFromRatio(10) , "2:1" );
    BOOST_CHECK_EQUAL( award.getGradeFromRatio(12.4) , "2:1" );
    BOOST_CHECK_EQUAL( award.getGradeFromRatio(3.5) , "3rd" );
    BOOST_CHECK_EQUAL( award.getGradeFromRatio(0) , "Fail" );
}

BOOST_AUTO_TEST_CASE( StubTest )
{
    BOOST_CHECK_EQUAL( 0 , 0 );
}

/////////////////////////////////////////////////////////////////////////////////////////
