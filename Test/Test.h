#ifndef AIZO2_TEST_H
#define AIZO2_TEST_H

#include <iostream>
#include <fstream>
#include "../Helpers/Generator.h"
#include "../AdjacencyList/AdjacencyList.h"
#include "../IncidenceMatrix/IncidenceMatrix.h"
#include <limits>
#include "../MST/Prim.h"
#include "../SP/Dijkstry.h"
#include "../SP/BellmanFord.h"

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
    void SpBellmanFordAlgorithm();
public:
    Test() {
    }

    void menu();
};


#endif //AIZO2_TEST_H
