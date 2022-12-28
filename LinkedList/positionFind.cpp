#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *next;
};

node *makeNode(int x) {
    node *tmp = new node();
    tmp->next = nullptr;
    tmp->data = x;
    return tmp;
}

void insertFirst(node *a, int x) {
    node *tmp = makeNode(x);
    if(a == nullptr) {
        a = tmp;
    } else {
        tmp->next = a;
        a = tmp;
    }
}

void display(node *a) {
    while(a != nullptr) {
        cout << a->data << " ";
        a = a->next;
    }
}

node *getNode(node *a, int k) {
    node *p = a;
    for(int i = 0;i < k; i++) {
        p = p->next;
    }
    return p;
}

int main() {
    int n, x, k;
    node *head = nullptr;
    cin >> n;
    while(n--) {
        cin >> x;
        insertFirst(head, x);
        display(head);
        cin >> k;
        getNode(head, k);
    }
    return 0;
}