
#include "Simulation.h"
#include "../AdjacencyList/AdjacencyList.h"
#include "../IncidenceMatrix/IncidenceMatrix.h"
#include "../MST/Prim.h"
#include "../SP/Dijkstry.h"
#include "../SP/BellmanFord.h"

void Simulation::resetTable() {
for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 7; j++) {
        avgTimePrimAdjacencyList[i][j] = 0;
        avgTimePrimIncidenceMatrix[i][j] = 0;
        avgTimeDijkstryAdjacencyList[i][j] = 0;
        avgTimeDijkstryIncidenceMatrix[i][j] = 0;
    }
}
}

void Simulation::displayTable() {
    cout << fixed << setprecision(3);
    cout << "Wyniki symulacji" << endl;
    cout << "Prim - Lista sasiedztwa" << endl;
    cout << setw(10) << "V" << setw(10) << "0.25" << setw(10) << "0.5" << setw(10) << "0.99" << endl;
    for (int i = 0; i < 7; i++) {
        cout << setw(10) << sizes[i];
        for (int j = 0; j < 3; j++) {
            cout << setw(10) << avgTimePrimAdjacencyList[j][i];
        }
        cout << endl;
    }

    cout << endl;
    cout << "Prim - Macierz incydencji" << endl;
    cout << setw(10) << "V" << setw(10) << "0.25" << setw(10) << "0.5" << setw(10) << "0.99" << endl;
    for (int i = 0; i < 7; i++) {
        cout << setw(10) << sizes[i];
        for (int j = 0; j < 3; j++) {
            cout << setw(10) << avgTimePrimIncidenceMatrix[j][i];
        }
        cout << endl;
    }

    cout << endl;
    cout << "Dijkstry - Lista sasiedztwa" << endl;
    cout << setw(10) << "V" << setw(10) << "0.25" << setw(10) << "0.5" << setw(10) << "0.99" << endl;
    for (int i = 0; i < 7; i++) {
        cout << setw(10) << sizes[i];
        for (int j = 0; j < 3; j++) {
            cout << setw(10) << avgTimeDijkstryAdjacencyList[j][i];
        }
        cout << endl;
    }

    cout << endl;
    cout << "Dijkstry - Macierz incydencji" << endl;
    cout << setw(10) << "V" << setw(10) << "0.25" << setw(10) << "0.5" << setw(10) << "0.99" << endl;
    for (int i = 0; i < 7; i++) {
        cout << setw(10) << sizes[i];
        for (int j = 0; j < 3; j++) {
            cout << setw(10) << avgTimeDijkstryIncidenceMatrix[j][i];
        }
        cout << endl;
    }

    cout << endl;
    cout << "Bellman-Ford - Lista sasiedztwa" << endl;
    cout << setw(10) << "V" << setw(10) << "0.25" << setw(10) << "0.5" << setw(10) << "0.99" << endl;
    for (int i = 0; i < 7; i++) {
        cout << setw(10) << sizes[i];
        for (int j = 0; j < 3; j++) {
            cout << setw(10) << avgTimeBellmanFordAdjacencyList[j][i];
        }
        cout << endl;
    }

    cout << endl;
    cout << "Bellman-Ford - Macierz incydencji" << endl;
    cout << setw(10) << "V" << setw(10) << "0.25" << setw(10) << "0.5" << setw(10) << "0.99" << endl;
    for (int i = 0; i < 7; i++) {
        cout << setw(10) << sizes[i];
        for (int j = 0; j < 3; j++) {
            cout << setw(10) << avgTimeBellmanFordIncidenceMatrix[j][i];
        }
        cout << endl;
    }

    cout << endl;
}

void Simulation::simulate() {

    simulateSP();
    simulateMST();

    displayTable();
}

void Simulation::simulateSP() {
    int V, E;
    float density;

    for (int d = 0; d < 3; d++) {
        density = densities[d];
        for (int j = 0; j < tableSize; j++) {
            V = sizes[j];
            cout<<"#" << V << "#";
            for (int i = 0; i < iterations; i++) {
                E = Generator::numberOfEdgesByDensityAndNodes(V, density);
                Edge *edges = Generator::generateEdges(V, E);

                auto adjacencyList = new AdjacencyList(V, E, edges, true);
                auto incidenceMatrix = new IncidenceMatrix(V, E, edges, true);

                auto dijksrtyAdjacencyList = new Dijkstry(*adjacencyList, 0, V - 1);
                auto dijksrtyIncidenceMatrix = new Dijkstry(*incidenceMatrix, 0, V - 1);

                avgTimeDijkstryAdjacencyList[d][j] += dijksrtyAdjacencyList->GetTime();
                avgTimeDijkstryIncidenceMatrix[d][j] += dijksrtyIncidenceMatrix->GetTime();

                auto bellmanFordAdjacencyList = new BellmanFord(*adjacencyList, 0, V - 1);
                auto bellmanFordIncidenceMatrix = new BellmanFord(*incidenceMatrix, 0, V - 1);

                avgTimeBellmanFordAdjacencyList[d][j] += bellmanFordAdjacencyList->GetTime();
                avgTimeBellmanFordIncidenceMatrix[d][j] += bellmanFordIncidenceMatrix->GetTime();

                adjacencyList->freeMemory();
                incidenceMatrix->freeMemory();

                dijksrtyAdjacencyList->freeMemory();
                dijksrtyIncidenceMatrix->freeMemory();

                bellmanFordAdjacencyList->freeMemory();
                bellmanFordIncidenceMatrix->freeMemory();
            }
        }
    }

    for (int d = 0; d < 3; d++) {
        for (int k = 0; k < 7; k++) {
            avgTimeDijkstryAdjacencyList[d][k] /= iterations;
            avgTimeDijkstryIncidenceMatrix[d][k] /= iterations;
        }
    }

    cout << endl;
}

void Simulation::simulateMST() {
    int V, E;
    float density;

    for (int d = 0; d < 3; d++) {
        density = densities[d];
        for (int j = 0; j < tableSize; j++) {
            V = sizes[j];
            cout<<"#";
            for (int i = 0; i < iterations; i++) {
                E = Generator::numberOfEdgesByDensityAndNodes(V, density);
                Edge *edges = Generator::generateEdges(V, E);

                auto adjacencyList = new AdjacencyList(V, E, edges, false);
                auto incidenceMatrix = new IncidenceMatrix(V, E, edges, false);

                auto primAdjacencyList = new Prim(*adjacencyList, V);
                auto primIncidenceMatrix = new Prim(*incidenceMatrix, V);

                avgTimePrimAdjacencyList[d][j] += primAdjacencyList->GetTime();
                avgTimePrimIncidenceMatrix[d][j] += primIncidenceMatrix->GetTime();

                adjacencyList->freeMemory();
                incidenceMatrix->freeMemory();

                primAdjacencyList->freeMemory();
                primIncidenceMatrix->freeMemory();
            }
        }
    }

    for (int d = 0; d < 3; d++) {
        for (int k = 0; k < 7; k++) {
            avgTimePrimAdjacencyList[d][k] /= iterations;
            avgTimePrimIncidenceMatrix[d][k] /= iterations;
        }
    }

    cout << endl;
}
