#include <iostream>
#include <vector>
#include <random>

using namespace std;

vector<int> creatVector(int &n) {
    vector<int> v;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, n);
    for (int i = 0; i < n; i++) {
        v.push_back(dis(gen));
    }
    return v;
}

vector<int> sumOfFirstAndLast(vector<int>& v) {
    vector<int> result;
    result.push_back(v[0] + v[v.size() - 1]);
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> v = creatVector(n);
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;

    v.pop_back();

    vector<int> newV = sumOfFirstAndLast(v);
    for (int i : newV) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}