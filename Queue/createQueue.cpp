#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *next;
};

struct node *makeNode(int x) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = nullptr;
    return newNode;
}

void push(struct node **q, int x) {
    struct node *newNode = makeNode(x);
    if(*q == nullptr) {
        *q = newNode;
        return;
    }
    struct node *tmp = *q;
    while(tmp->next != nullptr) {
        tmp = tmp->next;
    }
    tmp->next = newNode;
}

void pop(struct node **q) {
    if(*q == nullptr)
        return;
    struct node *tmp = *q;
    (*q) = (*q)->next;
    free(tmp);
}

int size(struct node *q) {
    int ans = 0;
    while(q != nullptr) {
        ++ans;
        q = q->next;
    }
    return ans;
}

bool isEmpty(struct node *q) {
    return q == nullptr;
}

int front(struct node *q) {
    return q->data;
}

void output(struct node *q) {
    while(q != nullptr) {
        printf("%d ", q->data);
        q = q->next;
    }
}