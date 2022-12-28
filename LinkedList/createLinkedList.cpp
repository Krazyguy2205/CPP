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

int size(Node *head) {
    int size = 0;
    while(head != nullptr) {
        ++size;
        head = head->next;
    }
    return size;
}

void pushFront(Node *&head, int x) {
    Node *newNode = makeNode(x);
    newNode->next = head;
    head = newNode;
}

void pushBack(Node *&head, int x) {
    Node *tmp = head;
    Node *newNode = makeNode(x);
    if(head == nullptr) {
        head = newNode;
        return;
    }
    while(tmp->next != nullptr) {
        tmp = tmp->next;
    }
    tmp->next = newNode;
}

void display(Node *head) {
    while(head != nullptr) {
        cout << head->data << ' ';
        head = head->next;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Node *head = nullptr;
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        pushFront(head, i);
    }
    display(head);
    return 0;
}