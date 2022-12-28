#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> stackConcat(const vector<int>& a, vector<int>& b) {
    stack<int> st1, st2;
    vector<int> v;
    for(int i : a) {
        st1.push(i);
    }

    for(int i : b) {
        st2.push(i);
    }

    stack<int> st3;
    while(!st1.empty() && !st2.empty()) {
        if(st1.top() > st2.top()) {
            st3.push(st1.top());
            st1.pop();
        } else {
            st3.push(st2.top());
            st2.pop();
        }
    }

    while(!st1.empty()) {
        st3.push(st1.top());
        st1.pop();
    }

    while(!st2.empty()) {
        st3.push(st2.top());
        st2.pop();
    }

    while(!st3.empty()) {
        v.push_back(st3.top());
        st3.pop();
    }
    return v;
}

int main() {
    vector<int> a = {1,3,4,5};
    vector<int> b = {6,8,10};
    vector<int> res = stackConcat(a, b);
    for(int re : res) {
        cout << re << " ";
    }
    return 0;
}