#include <iostream>
#include <vector>

using namespace std;

vector<int> initializeVector(int &n) {
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        v.push_back(i);
    }
    return v;
}

int sumOfVector(const vector<int>& v) {
    int sum = 0;
    for (int i : v) {
        sum += i;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<int> v = initializeVector(n);
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;
    cout << sumOfVector(v) << endl;
    return 0;
}
