#ifndef DEGREEAWARDS_H
#define DEGREEAWARDS_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

class degreeAwards {
public:
    float getMean(const std::vector<std::string>& inputGrades);

    std::string getMajority(const std::vector<std::string>& inputGrades);

    int getFinalYearGrade(const std::vector<std::string>& secondYearGrades, std::vector<std::string>& thirdYearGrades);

    std::string getGradeFromRatio(float inputGrade);

    static const std::map<std::string, int> GRADES;

    float gradeBoundary_Fail = 3.5f;
    float gradeBoundary_3rd = 6.5f;
    float gradeBoundary_22 = 9.5f;
    float gradeBoundary_21 = 12.5f;
};

#endif


