
#ifndef AIZO2_SIMPLESTRUCTURES_H
#define AIZO2_SIMPLESTRUCTURES_H
struct Edge {
    int src, dest, weight;
    Edge(int s = 0, int d = 0, int w = 0) : src(s), dest(d), weight(w) {}
};

struct AdjListNode {
    int dest, weight;
    struct AdjListNode* next;
};

struct AdjList {
    struct AdjListNode* head;
};

#endif //AIZO2_SIMPLESTRUCTURES_H
