#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1001];
bool visited[1001];

void input() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x); //co huong thi ko can
    }
    memset(visited, false, sizeof(visited));
}

void DFS(int u) {
    cout << u << " ";
    visited[u] = true;
    for(int v : adj[u]) {
        if(!visited[v])
            DFS(v);
    }
}

int main() {
    input();
    int u;
    cin >> u;
    DFS(u);

}