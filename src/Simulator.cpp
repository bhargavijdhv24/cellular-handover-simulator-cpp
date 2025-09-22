#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "BaseStation.h"
#include "MobileDevice.h"
#include "HandoverManager.h"

int main() {
    // Setup base stations
    std::vector<BaseStation> stations = {
        BaseStation(0,0), BaseStation(50,0), BaseStation(100,0)
    };

    // Define path of the mobile device (moving along x-axis)
    std::vector<std::pair<double,double>> path;
    for (int x = 0; x <= 120; x += 5) {
        path.push_back({x,0});
    }
    MobileDevice device(path);
    HandoverManager manager;

    std::ofstream logFile("data/handover_log.txt");

    // Run simulation
    while (device.hasNext()) {
        auto pos = device.move();

        std::map<int,double> strengths;
        for (int i = 0; i < (int)stations.size(); i++) {
            strengths[i] = stations[i].signalStrength(pos.first, pos.second);
        }

        int connectedBS = manager.decideHandover(strengths);
        logFile << pos.first << "," << pos.second 
                << ",BS" << connectedBS << "\n";

        std::cout << "Device at (" << pos.first << "," << pos.second 
                  << ") connected to BS" << connectedBS << std::endl;
    }

    logFile.close();
    return 0;
}
