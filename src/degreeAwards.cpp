#include "degreeAwards.h"

const std::map<std::string, int> degreeAwards::GRADES = {
    {"Exec 1st", 16},
    {"High 1st", 15},
    {"Mid 1st", 14},
    {"Low 1st", 13},
    {"High 2:1", 12},
    {"Mid 2:1", 11},
    {"Low 2:1", 10},
    {"High 2:2", 9},
    {"Mid 2:2", 8},
    {"Low 2:2", 7},
    {"High 3rd", 6},
    {"Mid 3rd", 5},
    {"Low 3rd", 4},
    {"Marg Fail", 3},
    {"Mid Fail", 2},
    {"Low Fail", 1},
    {"Zero", 0}
};

double degreeAwards::round(float num) {
    std::string value = std::to_string(num);
    size_t pos = value.find('.');
    return std::stod(value.substr(0, pos + 2));
};

double degreeAwards::getMean(const std::vector<std::string>& inputGrades) {
    double totalPoints = 0;
    for (std::string grade : inputGrades) {
        totalPoints += degreeAwards::GRADES.at(grade);
    }
    return round(totalPoints / inputGrades.size());
}

std::string degreeAwards::getMajority(const std::vector<std::string>& inputGrades) {
    std::unordered_map<std::string, int> modeMap;
    int count = 0;
    std::vector<int> majorityCounts;
    int highest = 0;
    std::string ret;

    // Calculate mode
    for (int i = 0; i < inputGrades.size(); i++) {
        std::string current = inputGrades[i];
        modeMap[current]++;
        count = std::max(count, modeMap[current]);
    }

    // Return modal grade from map
    for (auto pair : modeMap) {
        if (pair.second == count) {
            majorityCounts.push_back(0);
            if (count > highest) {
                highest = count;
                ret = pair.first;
            }
        }
    }

    if (majorityCounts.size() == inputGrades.size()) {
        return "Zero";
    } else {
        return ret;
    }
}


double degreeAwards::getFinalYearGrade(const std::vector<std::string>& secondYearGrades, std::vector<std::string>& thirdYearGrades) {
    double secondYearMean = getMean(secondYearGrades) * 0.2;
    double thirdYearMean = getMean(secondYearGrades) * 0.8;
    double finalMean = secondYearMean + thirdYearMean;

    std::string secondYearMajority = getMajority(secondYearGrades);
    thirdYearGrades.push_back(secondYearMajority);

    std::string finalYearMajority = getMajority(thirdYearGrades);
    double finalYearMajorityNumeric = degreeAwards::GRADES.at(finalYearMajority);

    return finalMean > finalYearMajorityNumeric ? finalMean : finalYearMajorityNumeric;
}

std::string degreeAwards::getGradeFromRatio(float inputGrade) {
    if (inputGrade < GRADEBOUNDARIES[0]) {return "Fail";}
    else if (inputGrade < GRADEBOUNDARIES[1]) {return "3rd";}
    else if (inputGrade < GRADEBOUNDARIES[2]) {return "2:2";}
    else if (inputGrade < GRADEBOUNDARIES[3]) {return "2:1";}
    return "1st";
}
