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
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}

void DFS(int u) {
    visited[u] = true;
    cout << u << " ";
    for(int v : adj[u]) {
        if(!visited[v])
            DFS(v);
    }
}

void connectedComponents() {
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            ++ans;
            DFS(i);
        }
    }
    cout << ans << endl;
}

int main() {
    input();
    connectedComponents();
}