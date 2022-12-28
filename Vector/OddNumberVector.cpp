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

int countOdd(const vector<int>& v) {
    int count = 0;
    for (int i : v) {
        if (i % 2 != 0) {
            count++;
        }
    }
    return count;
}

int countOddIterator(const vector<int>& v) {
    int count = 0;
    for (auto it = v.begin(); it != v.end(); it++) {
        if (*it % 2 != 0) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> v = initializeVector(n);
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;
    cout << countOdd(v) << endl;
    cout << countOddIterator(v) << endl;
    return 0;
}