#include <bits/stdc++.h>
using namespace std;

int v, e;
vector<int> adj[1001];
bool visited[1001];

void input() {
    cin >> v >> e;
    for (int i = 0; i < v; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}

void BFS(int u) {
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty()) {
        int a = q.front();
        q.pop();
        cout << a << " ";
        for(int b : adj[a]) {
            if(!visited[b]) {
                q.push(b);
                visited[b] = true;
            }
        }
    }
}

int main() {
    input();
    BFS(1);
    return 0;
}