#include <iostream>
#include <string>
#include <stack>

using namespace std;
using ll = long long;

string to_string(ll n) {
    string s;
    while(n > 0) {
        s += char (n % 10 + '0');
        n /= 10;
    }
    return s;
}

int main() {
    string s;
    getline(cin, s);
    s = s + '@';
    stack<char> st;
    string str;
    for(char & i : s) {
        if(st.empty() || st.top() == i) {
            st.push(i);
        } else {
            int count = 0;
            str += st.top();
            while(!st.empty()) {
                count++;
                st.pop();
            }
            str += to_string(count);
            st.push(i);
        }
    }
    cout << str;
    return 0;
}