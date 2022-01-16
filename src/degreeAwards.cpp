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

int main()
{
    std::string inputGrade;
    while(inputGrade != "Quit")
    {
        std::cin >> inputGrade;
        if (degreeAwards::GRADES.count(inputGrade)) {

        }
    }
}

int getMean(const std::vector<std::string>& inputGrades) {
    int totalPoints = 0;
    for (std::string grade : inputGrades) {
        totalPoints += degreeAwards::GRADES.at(grade);
    }
    return totalPoints / inputGrades.size();
}

int getMajority(const std::vector<std::string>& inputGrades) {
    std::unordered_map<std::string, int> modeMap;
    int count = 0;

    // Calculate mode
    for (int i = 0; i < inputGrades.size(); i++) {
        std::string current = inputGrades[i];
        modeMap[current]++;
        count = std::max(count, modeMap[current]);
    }

    // Return modal grade from map
    for (auto pair : modeMap) {
        if (pair.second == count) {
            return pair.second;
        }
    }
}
