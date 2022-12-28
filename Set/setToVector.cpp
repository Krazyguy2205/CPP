#include <iostream>
#include <set>
#include <vector>
using namespace std;

int add(vector<int> v) {
    set<int> s;
    for (int & i : v) {
        s.insert(i);
    }
    return s.size();
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int & i : v) {
        cin >> i;
    }
    cout << add(v) << endl;
    return 0;
}