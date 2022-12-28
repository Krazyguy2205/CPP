#include <bits/stdc++.h>
using namespace std;

vector<int> firstNegative(vector<int> a, int k) {
    queue<int> q;
    for(int i = 0; i < k - 1; ++i) {
        if(a[i] < 0) {
            q.push(i);
        }
    }

    vector<int> res;
    for(int i = k - 1; i < a.size(); ++i) {
        if(a[i] < 0) {
            q.push(i);
        }

        while(!q.empty() && q.front() < i - k + 1) {
            q.pop();
        }

        res.push_back(q.empty() ? 0 : a[q.front()]);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n;
    vector<int> a(n);
    for(auto & i : a) {
        cin >> i;
    }
    cin >> k;
    for(auto & i : firstNegative(a, k)) {
        cout << i << " ";
    }
}