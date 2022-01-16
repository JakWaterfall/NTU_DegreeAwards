#ifndef DEGREEAWARDS_H
#define DEGREEAWARDS_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

class degreeAwards {
public:
    double getMean(const std::vector<std::string>& inputGrades);
    std::string getMajority(const std::vector<std::string>& inputGrades);
    int getFinalYearGrade(const std::vector<std::string>& secondYearGrades, std::vector<std::string>& thirdYearGrades);
    std::string getGradeFromRatio(float inputGrade);

private:
    double round(float num);

    static const std::map<std::string, int> GRADES;
    const std::vector<float> GRADEBOUNDARIES = {3.5f, 6.5f, 9.5f, 12.5f}; // Fail, 3rd, 22, 21
};

#endif


