#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *makeNode(int data) {
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void push(Node *&top, int x) {
    Node *newNode = makeNode(x);
    if (top == nullptr) {
        top = newNode;
        return;
    }
    newNode->next = top;
    top = newNode;
}

void pop(Node *&top) {
    if (top != nullptr) {
        Node *tmp = top;
        top = tmp->next;
        delete tmp;
    }
}

int isEmpty(Node *st) {
    return (st == nullptr);
}

int Top(Node *top) {
    if (top != nullptr) {
        return top->data;
    }
}

void convert(int n, Node *&top) {
    int du;
    while(n > 0) {
        du = n % 2;
        push(top, du);
        n /= 2;
    }
}


int main() {
    Node *st = nullptr;
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            convert(n, st);
            while(st != nullptr) {
                cout << Top(st);
                pop(st);
            }
        }
    return 0;
}