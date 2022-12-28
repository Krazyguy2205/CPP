#include <iostream>
#include <vector>

using namespace std;

vector<int> initializeVector_1(int &n) {
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> v = initializeVector_1(n);
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    return 0;
}