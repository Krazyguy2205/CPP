#include <iostream>
#include <vector>
#include <string>
#include <random>

using namespace std;

vector<string> createVector(int &n) {
    vector<string> v;
    for (int i = 0; i < n; i++) {
        string s;
        cin.ignore();
        getline(cin, s);
        v.push_back(s);
    }
    return v;
}

//find the longest string in a vector
string longestString(vector<string>& v) {
    string longest = v[0];
    for (string s : v) {
        if (s.size() > longest.size()) {
            longest = s;
        }
    }
    return longest;
}

int main() {
    int n;
    cin >> n;
    vector<string> v = createVector(n);
    cout << longestString(v) << endl;
    return 0;
}