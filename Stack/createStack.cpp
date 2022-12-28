//Tạo stack sử dụng danh sach liên kết
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *makeNode(int x) {
    Node *newNode = new Node;
    newNode->data = x;
    newNode->next = nullptr;
    return newNode;
}

void push(Node *&top, int x) {
    Node *newNode = makeNode(x);
    if(top == nullptr) {
        top = newNode;
        return;
    }
    newNode->next = top;
    top = newNode;
}

void pop(Node *&top) {
    if(top != nullptr) {
        Node *tmp = top;
        top = tmp->next;
        delete tmp;
    }
}

int Top(Node *top) {
    if(top != nullptr) {
        return top->data;
    }
}

int size(Node *top) {
    int cnt = 0;
    while(top != nullptr) {
        ++cnt;
        top = top->next;
    }
    return cnt;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Node *st = nullptr;
    while(true) {
        cout << "1. push" << endl;
        cout << "2. pop" << endl;
        cout << "3. top" << endl;
        cout << "4. size" << endl;
        cout << "5. exit" << endl;
        int choose; cin >> choose;
        if(choose == 1) {
            int x; cin >> x;
            push(st, x);
        } else if(choose == 2) {
            pop(st);
        } else if(choose == 3) {
            if(st == nullptr) cout << "stack empty";
            cout << Top(st) << endl;
        } else if(choose == 4) {
            cout << size(st);
        } else {
            break;
        }
    }
    return 0;
}