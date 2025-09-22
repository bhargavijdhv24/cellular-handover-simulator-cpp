#ifndef BASESTATION_H
#define BASESTATION_H

#include <cmath>

class BaseStation {
private:
    double x, y;
    double power;

public:
    BaseStation(double x, double y, double power = 100.0);

    double signalStrength(double deviceX, double deviceY) const;
};

#endif
