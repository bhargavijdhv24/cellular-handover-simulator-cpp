#ifndef HANDOVERMANAGER_H
#define HANDOVERMANAGER_H

#include <map>

class HandoverManager {
private:
    int currentBS;
    double threshold;

public:
    HandoverManager(double threshold = 5.0);
    int decideHandover(const std::map<int,double>& strengths);
};

#endif
