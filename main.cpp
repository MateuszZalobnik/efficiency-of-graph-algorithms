#include <iostream>

#include "Helpers/Generator.h"
#include "AdjacencyList/AdjacencyList.h"
#include "IncidenceMatrix/IncidenceMatrix.h"
#include "MST/Kruskal.h"
#include "MST/Prim.h"
#include "ShortestPathAlgorithms/Dijkstry.h"
#include "Test/Test.h"
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

int main() {
    srand(time(NULL));

    int choice;

    do {
        cout << "Menu:" << endl;
        cout << "1. Symulacja" << endl;
        cout << "2. Test" << endl;
        cout << "3. Exit" << endl;
        cout << "Wybierz: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> choice;

        if (cin.fail()) {
            cout << "Wprowadź numer." << endl;
            continue;
        }
        if (choice == 1) {
//    Simulator simulator;
//    simulator.simulate();
        } else if (choice == 2) {
             Test test;
             test.menu();
        } else if (choice == 3) {
            cout << "Exiting..." << endl;
        } else {
            cout << "Zły wybór." << endl;
        }

    } while (choice != 3);







//
//    int V = 10; // Liczba wierzchołków
//    float density = 0.95; // gestosc
//
//    // Generowanie losowych krawędzi
//    int E = Generator::numberOfEdgesByDensityAndNodes(V, density);
//    Edge *edges = Generator::generateEdges(V, E);
//
//    auto incidenceMatrix = new IncidenceMatrix(V, E, edges, true);
//    incidenceMatrix->printMatrix();
//    auto adjacencyList = new AdjacencyList(V, E, edges, true);
//    adjacencyList->printGraph();
//
//
//
//    auto dijkstry = new Dijkstry(*incidenceMatrix, 0, 5);
//    cout << "koszt calkowity: ";
//    dijkstry->printTotalCost();
//    cout << endl;
//    dijkstry->printPath();
//
//    cout << endl;
//    cout << endl;
//    cout << endl;
//    auto dijkstry2 = new Dijkstry(*adjacencyList, 0, 5);
//    cout << endl;
//    cout << "koszt calkowity: ";
//    dijkstry2->printTotalCost();
//    cout << endl;
//    dijkstry2->printPath();




//     Wyświetlenie wygenerowanych krawędzi
//    cout << "krawedziue \n";
//    for (int i = 0; i < E; ++i) {
//        std::cout << "Edge " << i << ": (" << edges[i].src << ", "
//                  << edges[i].dest << ", " << edges[i].weight << ")\n";
//    }





//    auto result1 = Prim::primMST(*incidenceMatrix);
//    auto result2 = Prim::primMST(*adjacencyList);
//
//    cout << endl << "wynik " << endl;
//    for (int i = 0; i < V - 1; i++) {
//        std::cout << "Edge " << i << ": (" << result1[i].src << ", "
//                  << result1[i].dest << ", " << result1[i].weight << ")\n";
//    }
//    cout << endl << "wynik " << endl;
//
//    for (int i = 0; i < V - 1; i++) {
//        std::cout << "Edge " << i << ": (" << result2[i].src << ", "
//                  << result2[i].dest << ", " << result2[i].weight << ")\n";
//    }



// Zwolnienie pamięci
//adjacencyList->freeMemory();
//    incidenceMatrix->freeMemory();
//    delete[] edges;

    return 0;

}
