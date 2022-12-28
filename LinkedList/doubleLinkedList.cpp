#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *prev;
    node *next;
};

struct douList {
    node *head;
    node *tail;
};

node * makeNode(int x) {
    douList *tmp = new douList;
    tmp->head = new node;
    tmp->head->data = x;
    tmp->head->prev = nullptr;
    tmp->head->next = nullptr;
    tmp->tail = tmp->head;
    return tmp;
}

douList *addHead(douList *a, int x) {
    node *l = reinterpret_cast<node *>(makeNode(x));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}