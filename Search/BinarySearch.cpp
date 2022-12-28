#include <bits/stdc++.h>
using namespace std;

bool binarySearch(int a[], int n, int x) {
    int l = 0, r = n - 1;
    while(l <= r) {
        int m = (l + r) / 2;
        if(a[m] == x) {
            return true;
        } else if(a[m] < m) {
            l = m + 1;
        } else {
            r =  m - 1;
        }
    }
    return false;
}

bool recursionBs(int a[], int l, int r, int x) {
    if(l > r) return false;
    int m = (l + r) / 2;
    if(a[m] == x) {
        return true;
    } else if (a[m] < x) {
        return recursionBs(a, m + 1, r, x);
    } else {
        return recursionBs(a, l, m - 1, x);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> x;
    if(binarySearch(a, n, x)) {
        cout << "Found " << x << endl;
    } else {
        cout << "Not Found!" << endl;
    }

    if(recursionBs(a, 0, n-1, x)) {
        cout << "Found " << x << endl;
    } else {
        cout << "Not Found!" << endl;
    }
    return 0;
}



















