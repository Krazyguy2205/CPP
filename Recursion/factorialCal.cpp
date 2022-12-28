#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll factorial(ll n) {
    if(n == 0) return 1;
    return n * factorial(n - 1);
}

int main() {
    ll n; cin >> n;
    cout << factorial(n);
    return 0;
}