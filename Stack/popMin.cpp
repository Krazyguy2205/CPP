#include <bits/stdc++.h>
#include <stack>

using namespace std;

vector<int> popMin(vector<int> &v) {
    stack<int> st;
    vector<int> res;
    st.push(v[0]);
    for(int i = 1; i < v.size(); i++) {
        if(st.top() >= v[i]) {
            st.push(v[i]);
        } else {
            st.push(st.top());
        }
    }

    while(!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> res(n);
    for(int & re : res) {
        cin >> re;
    }

    for(auto x : popMin(res)) {
        cout << x << " ";
    }

    return 0;
}