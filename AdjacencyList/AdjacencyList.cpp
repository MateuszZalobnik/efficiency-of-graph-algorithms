
#include "AdjacencyList.h"

void AdjacencyList::addEdge(int src, int dest, int weight) {
    struct AdjListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = this->array[src].head;
    this->array[src].head = newNode;

    // Jeśli graf jest nieskierowany, dodaj również odwrotną krawędź
    if (!this->directed) {
        newNode = newAdjListNode(src, weight);
        newNode->next = this->array[dest].head;
        this->array[dest].head = newNode;
    }
}

struct AdjListNode* AdjacencyList::newAdjListNode(int dest, int weight) {
    auto* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = nullptr;
    return newNode;
}

void AdjacencyList::printGraph() {
    for (int v = 0; v < this->V; ++v) {
        struct AdjListNode* node = this->array[v].head;
        cout << endl << " [" << v << "]";
        while (node) {
            cout << " ->" << node->dest << ":" << node->weight;
            node = node->next;
        }
        cout << endl;
    }
}

void AdjacencyList::freeMemory() {
    for (int v = 0; v < this->V; ++v) {
        struct AdjListNode* pCrawl = this->array[v].head;
        while (pCrawl) {
            struct AdjListNode* temp = pCrawl;
            pCrawl = pCrawl->next;
            free(temp);
        }
    }
    delete[] this->array;
}
