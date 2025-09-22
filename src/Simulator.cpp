#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "BaseStation.h"
#include "MobileDevice.h"
#include "HandoverManager.h"

int main() {
    int numStations, pathEnd, step;
    std::cout << "Enter number of base stations: ";
    std::cin >> numStations;

    std::vector<BaseStation> stations;
    for (int i = 0; i < numStations; i++) {
        double x, y;
        std::cout << "Enter position of Base Station " << i << " (x y): ";
        std::cin >> x >> y;
        stations.emplace_back(x, y);
    }

    std::cout << "Enter path end position (x): ";
    std::cin >> pathEnd;
    std::cout << "Enter step size: ";
    std::cin >> step;

    // Define path
    std::vector<std::pair<double,double>> path;
    for (int x = 0; x <= pathEnd; x += step) {
        path.push_back({x,0});
    }
    MobileDevice device(path);
    HandoverManager manager;

    std::ofstream logFile("data/handover_log.txt");
    if (!logFile.is_open()) {
        std::cerr << "Error: could not open log file!" << std::endl;
        return 1;
    }

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
    std::cout << "\nSimulation finished! Results saved to data/handover_log.txt\n";
    std::cout << "Run plot_results.py to see the graph.\n";
    return 0;
}
