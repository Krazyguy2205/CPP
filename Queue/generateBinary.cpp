#include <bits/stdc++.h>

using namespace std;

vector<string> generateBinary(int n) {
    vector<string> res;
    queue<string> q;
    q.push("1");
    while(n--) {
        q.push(q.front() + "0");
        q.push(q.front() + "1");
        res.push_back(q.front());
        q.pop();
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    int n;
    cin >> n;
    vector<string> v = generateBinary(n);
    for(auto & i : v) {
        cout << i << endl;
    }
    return 0;
}

