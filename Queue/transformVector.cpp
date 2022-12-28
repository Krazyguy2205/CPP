#include <bits/stdc++.h>

using namespace std;

vector<int> transformVector(vector<int>& arr, int k) {
    vector<int> v;
    queue<int> q;
    for(int & i : arr) {
        q.push(i);
    }

    for(int i = 0; i < k; i++) {
        int x = q.front();
        q.push(x);
        q.pop();
    }

    while(!q.empty()) {
        v.push_back(q.front());
        q.pop();
    }
    return v;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int & i : arr) {
        cin >> i;
    }
    vector<int> v = transformVector(arr, k);
    return 0;
}