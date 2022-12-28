#include <iostream>
#include <string>
#include <stack>

using namespace std;
using ll = long long;

string stackBin(ll n) {
    string s;
    stack<int> st;
    while(n > 0) {
        st.push(n % 2);
        n /= 2;
    }

    while(!st.empty()) {
        s += to_string(st.top());
        st.pop();
    }
    return s;
}

int main() {
    int t; cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << stackBin(n) << endl;
    }
    return 0;
}