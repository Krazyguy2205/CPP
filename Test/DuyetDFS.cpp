#include <bits/stdc++.h>

bool visited[101];

struct Graph {
    int n;
    int a[10][10];
};

void readFile(Graph &g) {
    FILE *f = fopen("Test/graph.txt", "r");
    fscanf(f, "%d", &g.n);
    for(int i = 0; i < g.n; i++) {
        for(int j = 0; j < g.n; j++) {
            fscanf(f, "%d", &g.a[i][j]);
        }
    }
    fclose(f);
}

void output(Graph g) {
    printf("So dinh man tran %d: \n", g.n);
    for(int i = 0; i < g.n; i++) {
        for(int j = 0; j < g.n; j++) {
            printf("%d ", g.a[i][j]);
        }
        printf("\n");
    }
}

void DFS(Graph g, int v) {
    visited[v] = false;
    printf("Duyet dinh: %d\n", v);
    for(int u = 0; u < g.n; u++) {
        if(g.a[v][u] && visited[u]) {
            DFS(g, u);
        }
    }
}

int main() {
    Graph g{};
    readFile(g);
    output(g);
    for(int i = 0; i < g.n; i++) {
        visited[i] = true;
    }

    for(int i = 0; i <g.n; i++) {
        if(visited[i]) {
            DFS(g, i);
        }
    }
}


