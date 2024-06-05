#include <iostream>

#include "Helpers/Generator.h"
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node {
    int vertex;
    Node* next;
};
// Funkcja do dodawania krawędzi do listy sąsiedztwa
void addEdge(Node** adjacencyList, int u, int v) {
    // Dodanie wierzchołka v do listy sąsiedztwa u
    Node* newNode = new Node;
    newNode->vertex = v;
    newNode->next = adjacencyList[u];
    adjacencyList[u] = newNode;

    // Dodanie wierzchołka u do listy sąsiedztwa v (dla grafu nieskierowanego)
    newNode = new Node;
    newNode->vertex = u;
    newNode->next = adjacencyList[v];
    adjacencyList[v] = newNode;
}

int main() {
    srand(time(NULL));

    int V = 5; // Liczba wierzchołków
    float density = 0.5; // gestosc
    int max_edges = (V*(V-1))/2;
    int E = density * max_edges;

    Node** adjacencyList = new Node*[V];
    for (int i = 0; i < V; ++i) {
        adjacencyList[i] = nullptr; // Inicjalizacja pustymi listami
    }


    // Generowanie losowych krawędzi
    int **edges = Generator::generateEdges(V, E);

    int **incidenceMatrix = Generator::createIncidenceMatrix(V, E, edges);

    // Wyświetlenie wygenerowanych krawędzi
    cout << "Wygenerowane krawędzie (wierzchołek1, wierzchołek2):" << endl;
    for (int i = 0; i < E; i++) {
        cout << "(" << edges[i][0] << ", " << edges[i][1] << ")" << endl;
    }


// Wyświetlenie macierzy incydencji
    cout << "\nMacierz incydencji:" << endl;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < E; ++j) {
            cout << incidenceMatrix[i][j] << " ";
        }
        cout << endl;
    }

// Zwolnienie pamięci
    for (int i = 0; i < E; ++i) {
        delete[] edges[i];
    }
    delete[] edges;

    for (int i = 0; i < V; ++i) {
        delete[] incidenceMatrix[i];
    }
    delete[] incidenceMatrix;

    return 0;

}
