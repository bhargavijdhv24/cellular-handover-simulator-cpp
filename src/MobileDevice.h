#ifndef MOBILEDEVICE_H
#define MOBILEDEVICE_H

#include <vector>
#include <utility>

class MobileDevice {
private:
    std::vector<std::pair<double,double>> path;
    int currentIndex;

public:
    MobileDevice(const std::vector<std::pair<double,double>>& path);
    std::pair<double,double> move();
    bool hasNext() const;
};

#endif
