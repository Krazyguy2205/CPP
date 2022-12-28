#include <bits/stdc++.h>
using namespace std;

int n = 0, Stack[10001];

void push(int x) {
    Stack[n] = x;
    ++n;
}

void pop() {
    if(n >= 1) {
        --n;
    }
}

int top() {
    return Stack[n - 1];
}

int size() {
    return n;
}

int main() {
    while(true) {
        cout << "1. push" << endl;
        cout << "2. pop" << endl;
        cout << "3. top" << endl;
        cout << "4. size" << endl;
        cout << "5. exit" << endl;
        int choose; cin >> choose;
        if(choose == 1) {
            int x; cin >> x;
            push(x);
        } else if(choose == 2) {
            pop();
        } else if(choose == 3) {
            if(n == 0) cout << "stack empty";
            cout << top() << endl;
        } else if(choose == 4) {
            cout << size();
        } else {
            break;
        }
    }
    return 0;
}