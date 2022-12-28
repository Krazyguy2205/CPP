#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int cnt[10000001];
    int a[n];
    int m = INT_MIN;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
        m = max(m, a[i]);
    }

    for(int i = 0; i <= m; i++) {
        if(cnt[i] != 0) {
            for(int j = 0; j < cnt[i]; j++) {
                cout << i << ' ';
            }
        }
    }
    return 0;
}