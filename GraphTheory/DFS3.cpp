#include <bits/stdc++.h>
using namespace std;
//Do thi co huong
int v, e;
vector<int> adj[1001];
bool visited[1001];

void input() {
    cin >> v >> e;
    for(int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    memset(visited, false, sizeof(visited));
}

void DFS(int u) {
    cout << u << " ";
    visited[u] = true;
    for(int a : adj[u]) {
        if(!visited[a]) {
            DFS(a);
        }
    }
}

int main() {
    input();
    DFS(1);
    return 0;
}