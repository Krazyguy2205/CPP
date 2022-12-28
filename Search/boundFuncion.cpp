#include <bits/stdc++.h>
using namespace std;

//lower_bound(iter1, iter2, key) -> tra ve vi tri phan tu dau tien >= key
//upper_bound(iter1, iter2, key) -> tra ve vi tri phan tu dau tien > key

int main() {
    int n, x;
    cin >> n >> x;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto it = lower_bound(a, a + n, x);
    auto it2 = upper_bound(a, a+n, x);
    cout << it - a << " " << it2 - a;
    return 0;
}