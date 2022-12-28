#include <iostream>
#include <vector>
#include <random>

using namespace std;

vector<int> randomVector(int &n) {
    vector<int> v;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, n);
    for (int i = 0; i < n; i++) {
        v.push_back(dis(gen));
    }
    return v;
}

int main() {
    int n;
    cin >> n;
    vector<int> v = randomVector(n);
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}