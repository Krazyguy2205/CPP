#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node *makeNode(int x) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void NLR(struct node *root) {
    if(root != nullptr) {
        printf("%d ", root->data);
        NLR(root->left);
        NLR(root->right);
    }
}

void LNR(struct node *root) {
    if(root != nullptr) {
        LNR(root->left);
        printf("%d ", root->data);
        LNR(root->right);
    }
}

void LRN(struct node *root) {
    if(root != nullptr) {
        LRN(root->left);
        LRN(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct node *root = nullptr;
}
