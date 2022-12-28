#include <iostream>
#include <stack>
#include <string>

using namespace std;

string reverseString(string s) {
    string res;
    stack<char> st;
    for(char & i : s) {
        st.push(i);
    }

    while(!st.empty()) {
        res += st.top();
        st.pop();
    }
    return res;
}

int main() {
    string s;
    getline(cin, s);
    cout << reverseString(s) << endl;
    return 0;
}