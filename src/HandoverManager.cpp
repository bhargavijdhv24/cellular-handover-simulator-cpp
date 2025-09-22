#include "HandoverManager.h"

HandoverManager::HandoverManager(double threshold)
    : currentBS(-1), threshold(threshold) {}

int HandoverManager::decideHandover(const std::map<int,double>& strengths) {
    int bestBS = -1;
    double bestStrength = -1;

    for (auto& kv : strengths) {
        if (kv.second > bestStrength) {
            bestStrength = kv.second;
            bestBS = kv.first;
        }
    }

    if (currentBS == -1 || 
        bestStrength - strengths.at(currentBS) > threshold) {
        currentBS = bestBS;
    }
    return currentBS;
}
