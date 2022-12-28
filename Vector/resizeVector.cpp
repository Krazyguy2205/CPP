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

void resizeVector(vector<int>& v) {
    int x;
    cin >> x;
    v.resize(x);
    for(int & it : v) {
        cout << it << " ";
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> v = initializeVector(n);
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;
    resizeVector(v);
    return 0;
}
