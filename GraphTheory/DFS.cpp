#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *next;
};

struct Graph {
    int numVertices;
    int *traversed;
    node **adjList;
};

void DFS(Graph *g, int data) {
    node *adjList = g->adjList[data];
    node *tmp = adjList;

    g->traversed[data] = 1;
    cout << data << " da duyet" << endl;

    while(tmp != nullptr) {
        int connectedData = tmp->data;
        if(g->traversed[connectedData] == 0) {
            DFS(g, connectedData);
        }
        tmp = tmp->next;
    }
}

node *makeNode(int v) {
    node *newNode = new node;
    newNode->data = v;
    newNode->next = nullptr;
    return newNode;
}

Graph *createGraph(int vertices) {
    auto *g = new Graph;
    g->numVertices = vertices;
    g->adjList = new node*[vertices];
    g->traversed = new int[vertices];
    for(int i = 0; i < vertices; i++) {
        g->adjList[i] = nullptr;
        g->traversed[i] = 0;
    }
    return g;
}

void addEdge(Graph *g, int src, int dest) {
    node *newNode = makeNode(dest);
    newNode->next = g->adjList[src];
    g->adjList[src] = newNode;
    newNode = makeNode(src);
    newNode->next = g->adjList[dest];
    g->adjList[dest] = newNode;
}

void print(Graph *g) {
    for(int v  = 0;v < g->numVertices; v++) {
        node *tmp = g->adjList[v];
        cout << "Danh sach ke cua dinh " << v << " ";
        while(tmp) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }
}

int main() {

    Graph *g = createGraph(6);
    addEdge(g, 2, 3);
    addEdge(g, 2, 4);
    addEdge(g, 3, 4);
    addEdge(g, 4, 5);
    print(g);
    DFS(g, 4);
    return 0;
}