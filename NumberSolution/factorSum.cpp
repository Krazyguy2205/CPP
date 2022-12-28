#include <bits/stdc++.h>

using namespace std;

int solve(int n) {
    int k = 2, sum = 0;
    while(n > 1) {
        while(n % k == 0) {
            sum += k;
            n /= k;
        }
        k++;
    }
    return sum;
}

int factorSum(int n) {
    while(n != solve(n)) {
        n = solve(n);
    }
    return n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    do {
        cin >> n;
    }while(n < 2);
    cout << factorSum(n) << endl;
    return 0;
}