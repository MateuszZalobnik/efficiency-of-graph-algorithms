
#ifndef AIZO2_SIMULATION_H
#define AIZO2_SIMULATION_H

#include <iostream>
#include <iomanip>

using namespace std;

class Simulation {
private:
    int iterations = 50;
    int tableSize = 7;
    int sizes[7] = {100, 20, 20, 20, 20, 20, 20};
    float densities[3] = {0.25, 0.5, 0.99};
    double avgTimePrimAdjacencyList[3][7];
    double avgTimePrimIncidenceMatrix[3][7];
    double avgTimeDijkstryAdjacencyList[3][7];
    double avgTimeDijkstryIncidenceMatrix[3][7];
    double avgTimeBellmanFordIncidenceMatrix[3][7];
    double avgTimeBellmanFordAdjacencyList[3][7];
    void simulateSP();
    void resetTable();
    void simulateMST();
public:
    Simulation() {
        resetTable();
    };

    void simulate();

    void displayTable();

};


#endif //AIZO2_SIMULATION_H
