#include "BaseStation.h"

BaseStation::BaseStation(double x, double y, double power) 
    : x(x), y(y), power(power) {}

double BaseStation::signalStrength(double deviceX, double deviceY) const {
    double dx = x - deviceX;
    double dy = y - deviceY;
    double distance = sqrt(dx*dx + dy*dy);
    return power / (distance * distance + 1); // +1 avoids divide by zero
}
