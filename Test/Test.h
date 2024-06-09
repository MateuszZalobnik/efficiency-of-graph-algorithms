#ifndef AIZO1_TEST_H
#define AIZO1_TEST_H

#include <iostream>
#include <fstream>
#include "../Helpers/Generator.h"
#include "../AdjacencyList/AdjacencyList.h"
#include "../IncidenceMatrix/IncidenceMatrix.h"
#include <limits>

using namespace std;

class Test {
private:
    int V;
    int E;
    AdjacencyList *adjacencyList;
    IncidenceMatrix *incidenceMatrix;
    void GraphFromFile();
    void generateRandomGraph();
    void displayGraph();
    void close();
    void MstPrimAlgorithm();
    void SpDijkstryAlgorithm();
public:
    Test() {
    }

    void menu();
};


#endif //AIZO1_TEST_H
