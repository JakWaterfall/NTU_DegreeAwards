#ifndef DEGREEAWARDS_H
#define DEGREEAWARDS_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

class degreeAwards {
public:
    int getMean(const std::vector<std::string>& inputGrades);

    static const std::map<std::string, int> GRADES;
};

#endif
