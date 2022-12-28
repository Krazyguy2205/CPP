#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> st;
    vector<int> v;
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for(int & i : v) {
        st.push(v[i]);
    }

    while(!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}
