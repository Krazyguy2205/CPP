#include <iostream>
#include <stack>
#include <string>

using namespace std;

int reversals(string exp) {
    const auto len = exp.length();

    if (len % 2){
        return -1;
    }

    stack<char> st;

    for(const auto c: exp) {
        if (c == '}') {
            if(!st.empty() && st.top() == '{') {
                st.pop();
                continue;
            }
        }

        st.push(c);
    }

    int ret = 0;

    while( !st.empty()) {
        const auto t1 = st.top();
        st.pop();
        const auto t2 = st.top();
        st.pop();

        if(t1 != t2) {
            ret ++;
        }
        ret++;
    }

    return ret;
}

int main() {
    int n;
    cin >> n;
    string exp;
    getline(cin, exp);
    cout << reversals(exp) << endl;
    return 0;
}