#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n) {
    if(n < 2) return false;
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) return false;
    }
    return true;
}

vector<int> superPrime(int n) {
    queue<int> q;
    vector<int> v;
    for(int i = 2; i <= n, i < 10; i++) {
        if(isPrime(i)) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        for(int i = 1; i <= 9; i++) {
            int k = q.front()*10 + i;
            if(k <= n && isPrime(k)) {
                q.push(q.front()*10 + i);
            }
        }
        v.push_back(q.front());
        q.pop();
    }
    return v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v = superPrime(n);
    for(auto & i : v) {
        cout << i << " ";
    }
    return 0;
}

