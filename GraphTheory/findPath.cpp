#include <bits/stdc++.h>
using namespace std;

int v, e, s, t;
vector<int> adj[1001];
bool visited[1001];
int parent[1001];

void DFS(int u) {
    visited[u] = true;
    for(int x : adj[u]) {
        if(!visited[x]) {
            parent[x] = u;
            DFS(x);
        }
    }
}

void path() {
    cin >> s >> t;
    memset(visited, false, sizeof(visited));
    memset(parent, 0, sizeof(parent));
    DFS(s);
    if(!visited[t]) {
        cout << "No path found" << endl;
    } else {
        vector<int> path;
        while(t != s) {
            path.push_back(t);
            t = parent[t];
        }
        path.push_back(s);
        reverse(path.begin(), path.end());
        for(int x : path) {
            cout << x << " ";
        }
    }
}

void input() {
    cin >> v >> e;
    for(int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

int main() {
    input();
    path();
    return 0;
}