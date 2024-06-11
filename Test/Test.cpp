#include "Test.h"
#include "../MST/Prim.h"
#include "../SP/Dijkstry.h"
#include "../SP/BellmanFord.h"

void Test::GraphFromFile() {
    // wybór czy graf jest skierowany
    bool directed;
    cout << "czy graf jest skierowany? (t/n): ";
    char c;
    cin >> c;
    while (c != 't' && c != 'n') {
        cout << "Podaj t lub n: ";
        cin >> c;
    }
    directed = c == 't';

    string name;
    cout << endl;
    cout << "Podaj nazwe pliku: ";
    cin >> name;

    ifstream file;
    file.open(name.c_str());

    if (file.is_open()) { // Sprawdzenie, czy plik został otwarty poprawnie
        int numEdges, numVertices;
        file >> numEdges >> numVertices;

        Edge *edges = new Edge[numEdges];

        for (int i = 0; i < numEdges; ++i) {
            int src, dest, weight;
            file >> src >> dest >> weight;
            edges[i] = Edge(src, dest, weight);
        }

        // inicializacja listy sąsiedztwa i macierzy incydencji
        incidenceMatrix = new IncidenceMatrix(numVertices, numEdges, edges, directed);
        adjacencyList = new AdjacencyList(numVertices, numEdges, edges, directed);

        delete[] edges;
        file.close();
        cout << "Graf wczytany z pliku:\n";

    } else {
        cout << "Nie można otworzyć pliku " << name << endl;
    }

}

void Test::menu() {
    int choice;

    do {
        cout << "Menu:" << endl;
        cout << "1. Wczytaj dane z pliku" << endl;
        cout << "2. Wygeneruj graf losowo" << endl;
        cout << "3. Wyświetl graf listowo i macierzowo" << endl;
        cout << "4. Wykonaj algorytm MST Prima" << endl;
        cout << "5. Wykonaj algorytm SP Dijkstry" << endl;
        cout << "6. Wykonaj algorytm SP Bellmana-Forda" << endl;
        cout << "7. Wróć" << endl;
        cout << "Wybierz: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> choice;

        if (cin.fail()) {
            cout << "Wprowadź numer." << endl;
            continue;
        }
        if (choice == 1) {
            GraphFromFile();
        } else if (choice == 2) {
            generateRandomGraph();
        } else if (choice == 3) {
            displayGraph();
        } else if (choice == 4) {
            MstPrimAlgorithm();
        } else if (choice == 5) {
            SpDijkstryAlgorithm();
        } else if (choice == 6) {
            SpBellmanFordAlgorithm();
        } else if (choice == 7) {
            close();
        } else {
            cout << "Zły wybór." << endl;
        }

    } while (choice != 7);
}

void Test::displayGraph() {
    adjacencyList->printGraph();
    cout << endl;
    cout << endl;
    incidenceMatrix->printMatrix();
}

void Test::close() {
    // zwolnienie pamięci
    incidenceMatrix->freeMemory();
    adjacencyList->freeMemory();
    cout << endl;
}

void Test::generateRandomGraph() {
    // wczytanie liczby wierzchołków i gestosci
    float density;
    cout << "Podaj liczbę wierzchołków: ";
    cin >> V;
    cout << "Podaj gestosc: ";
    cin >> density;

    while (density < 0 || density > 1) {
        cout << "Gestosc musi byc z przedzialu [0, 1]. Podaj gestosc: ";
        cin >> density;
    }

    // wybór czy graf jest skierowany
    bool directed;
    cout << "czy graf jest skierowany? (t/n): ";
    char c;
    cin >> c;
    while (c != 't' && c != 'n') {
        cout << "Podaj t lub n: ";
        cin >> c;
    }
    directed = c == 't';

    E = Generator::numberOfEdgesByDensityAndNodes(V, density);
    Edge *edges = Generator::generateEdges(V, E);

    incidenceMatrix = new IncidenceMatrix(V, E, edges, directed);
    adjacencyList = new AdjacencyList(V, E, edges, directed);
}

void Test::MstPrimAlgorithm() {
    // wykonanie algorytmu MST Prima
    auto primIncidence = Prim(*incidenceMatrix, this->V);
    auto primAdjacency = Prim(*adjacencyList, this->V);

    cout << "Macierz incydencji:" << endl;
    cout << "Czas wykonania: " << primIncidence.GetTime() << "ms\n";
    cout << "Krawędzie mst: " << endl;
    primIncidence.printResult();

    cout << endl;
    cout << endl;
    cout << endl;

    cout << "Lista sąsiedztwa:" << endl;
    cout << "Czas wykonania: " << primAdjacency.GetTime() << "ms\n";
    cout << "Krawędzie mst: " << endl;
    primAdjacency.printResult();

    cout << endl;
    // zwolnienie pamięci
    primIncidence.freeMemory();
    primAdjacency.freeMemory();
}

void Test::SpDijkstryAlgorithm() {
    int start = -1;
    cout << "Podaj wierzchołek początkowy: ";
    cin >> start;
    while (start < 0){
        cout << "Podaj wierzchołek początkowy: ";
        cin >> start;
    }

    int end = -1;
    cout << "Podaj wierzchołek końcowy: ";
    cin >> end;
    while (end < 0){
        cout << "Podaj wierzchołek końcowy: ";
        cin >> end;
    }

    auto incidenceDijkstry = new Dijkstry(*incidenceMatrix, start, end);
    cout << "Macierz incydencji:" << endl;
    cout << "Czas wykonania: " << incidenceDijkstry->GetTime() << "ms\n";
    cout << "koszt calkowity: ";
    incidenceDijkstry->printTotalCost();
    cout << endl;
    incidenceDijkstry->printPath();

    cout << endl;
    cout << endl;
    cout << endl;

    auto adjacencyDijkstry = new Dijkstry(*adjacencyList, start, end);
    cout << "lista sąsiedztwa:" << endl;
    cout << "Czas wykonania: " << adjacencyDijkstry->GetTime() << "ms\n";
    cout << "koszt calkowity: ";
    adjacencyDijkstry->printTotalCost();
    cout << endl;
    adjacencyDijkstry->printPath();

    // czyszczenie pamieci
    adjacencyDijkstry->freeMemory();
    incidenceDijkstry->freeMemory();

    cout << endl;
    cout << endl;
}

void Test::SpBellmanFordAlgorithm() {
int start = -1;
    cout << "Podaj wierzchołek początkowy: ";
    cin >> start;
    while (start < 0){
        cout << "Podaj wierzchołek początkowy: ";
        cin >> start;
    }

    int end = -1;
    cout << "Podaj wierzchołek końcowy: ";
    cin >> end;
    while (end < 0){
        cout << "Podaj wierzchołek końcowy: ";
        cin >> end;
    }

    auto incidenceBellmanFord = new BellmanFord(*incidenceMatrix, start, end);
    cout << "Macierz incydencji:" << endl;
    cout << "Czas wykonania: " << incidenceBellmanFord->GetTime() << "ms\n";
    cout << "koszt calkowity: ";
    incidenceBellmanFord->printTotalCost();
    cout << endl;
    incidenceBellmanFord->printPath();

    cout << endl;
    cout << endl;
    cout << endl;

    auto adjacencyBellmanFord = new BellmanFord(*adjacencyList, start, end);
    cout << "lista sąsiedztwa:" << endl;
    cout << "Czas wykonania: " << adjacencyBellmanFord->GetTime() << "ms\n";
    cout << "koszt calkowity: ";
    adjacencyBellmanFord->printTotalCost();
    cout << endl;
    adjacencyBellmanFord->printPath();

    // czyszczenie pamieci
    adjacencyBellmanFord->freeMemory();
    incidenceBellmanFord->freeMemory();

    cout << endl;
    cout << endl;
}
