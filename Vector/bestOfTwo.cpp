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

int bestOfTwo(vector<int>& v) {
    int max = v[0] * v[1];
    for(int i = 0; i < v.size(); i++) {
        for(int j = i + 1; j < v.size(); j++) {
            if(v[i] * v[j] > max) {
                max = v[i] * v[j];
            }
        }
    }
    return max;
}

int main() {
    int n;
    cin >> n;
    vector<int> v = randomVector(n);
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;
    cout << bestOfTwo(v) << endl;
    return 0;
}
