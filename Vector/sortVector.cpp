#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> initializeVector(int &n) {
    vector<int> v;
    int value;
    for (int i = 0; i < n; i++) {
        cin >> value;
        v.push_back(value);
    }
    return v;
}

void sortVector(vector<int>& v) {
    sort(v.begin(), v.end());
}

void showVector(const vector<int>& v) {
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> v = initializeVector(n);
    showVector(v);
    sortVector(v);
    showVector(v);
    return 0;
}