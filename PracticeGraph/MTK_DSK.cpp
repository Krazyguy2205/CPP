#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> edge;
vector<int> adj[1001];
int a[1001][1001];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(a[i][j]) {
                adj[i].push_back(j);
                //adj[j].push_back(i);
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << i << " : ";
        for(int x : adj[i]) {
            cout << x << " ";
        }
        cout << endl;
    }
}