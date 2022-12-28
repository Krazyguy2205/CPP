#include <bits/stdc++.h>
using namespace std;

void insertionSort(int a[], int n) {
    for(int i = 1; i < n; i++) {
        int x = a[i], pos = i - 1;
        while(pos >= 0 && x < a[pos]) {
            a[pos+1] = a[pos];
            --pos;
        }
        a[pos+1] = x;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    insertionSort(a, n);
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}