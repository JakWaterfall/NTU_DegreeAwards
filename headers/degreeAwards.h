#ifndef DEGREEAWARDS_H
#define DEGREEAWARDS_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

class degreeAwards {
public:
    int getMean(const std::vector<std::string>& inputGrades);

    int getMajority(const std::vector<std::string>& inputGrades);

    int getFinalYearGrade(const std::vector<std::string>& secondYearGrades, const std::vector<std::string>& thirdYearGrades);

    int getGradeFromRatio(int inputGrade);

    static const std::map<std::string, int> GRADES;
};

#endif
