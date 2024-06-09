#include <iostream>

#include "Helpers/Generator.h"
#include "AdjacencyList/AdjacencyList.h"
#include "IncidenceMatrix/IncidenceMatrix.h"
#include "MST/Kruskal.h"
#include "MST/Prim.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(NULL));

    int V = 10; // Liczba wierzchołków
    float density = 0.95; // gestosc

    // Generowanie losowych krawędzi
    int E = Generator::numberOfEdgesByDensityAndNodes(V, density);
    Edge *edges = Generator::generateEdges(V, E);

    auto incidenceMatrix = new IncidenceMatrix(V, E, edges);
    incidenceMatrix->printMatrix();
    auto adjacencyList = new AdjacencyList(V, E, edges);
    adjacencyList->printGraph();


    // Kruskal's algorithm
//    auto result = Kruskal::kruskalMST(edges, V, E);

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
adjacencyList->freeMemory();
    incidenceMatrix->freeMemory();
    delete[] edges;

    return 0;

}
