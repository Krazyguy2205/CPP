#include <bits/stdc++.h>
using namespace std;

void dec_to_bin(long long number) {
    stack<int> stk;
    while(number > 0) {
        long long rem = number % 2; //take remainder
        number = number / 2;
        stk.push(rem);
    }
    while(!stk.empty()) {
        int item;
        item = stk.top();
        stk.pop();
        cout << item;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long number;
        cin >> number;
        dec_to_bin(number);
    }
}