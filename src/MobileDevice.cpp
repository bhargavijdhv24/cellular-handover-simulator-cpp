#include "MobileDevice.h"

MobileDevice::MobileDevice(const std::vector<std::pair<double,double>>& path)
    : path(path), currentIndex(0) {}

std::pair<double,double> MobileDevice::move() {
    if (currentIndex < (int)path.size()-1) {
        currentIndex++;
    }
    return path[currentIndex];
}

bool MobileDevice::hasNext() const {
    return currentIndex < (int)path.size()-1;
}
