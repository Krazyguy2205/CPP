#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

void repeatString(stack<char> &sc, string str, int num) {
    string res;
    for(int i = 0; i < num; i++) {
        for(auto x : str) {
            sc.push(x);
        }
    }
}

string decodeString(string s) {
    stack<char> sc;
    for(auto x : s) {
        if(x == ']') {
            string chr;
            string ans;
            int num = 0, base = 1;

            while(sc.top() != '[') {
                chr = sc.top();
                sc.pop();
                ans += chr;
            }

            sc.pop();
            while(!sc.empty() && '0' <= sc.top() && sc.top() <= '9') {
                num += (sc.top() - '0') * base;
                base *= 10;
                sc.pop();
            }
            repeatString(sc, ans, num);
        } else {
            sc.push(x);
        }
    }

    string res;
    while(!sc.empty()) {
        char x = sc.top();
        res.push_back(x);
        sc.pop();
    }

    reverse(res.begin(), res.end());
    return res;
}

int main() {
    string s;
    getline(cin, s);
    cout << decodeString(s) << endl;
    return 0;
}