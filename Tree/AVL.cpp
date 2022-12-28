#include <bits/stdc++.h>

using namespace std;

struct node {
    int data, height;
    node *left, *right;
};

int findMax(int a, int b) {
    return (a > b)?a : b;
}

int getHeight(node *root) {
    if(root == nullptr) return 0;
    return root->height;
}

node *makeNode(int x) {
    node *newNode = new node;
    newNode->data = x;
    newNode->height = 1;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

node *rotateRight(node *root) {
    node *x = root->left;
    node *t2 = x->right;
    x->right = root;
    root->left = t2;
    root->height = findMax(getHeight(root->left), getHeight(root->right) + 1);
    x->height = findMax(getHeight(x->left), getHeight(x->right) + 1);
    return x;
}

node *rotateLeft(node *root) {
    node *y = root->right;
    node *t2 = y->left;
    y->left = root;
    root->right = t2;
    root->height = findMax(getHeight(root->left), getHeight(root->right) + 1);
    y->height = findMax(getHeight(y->left), getHeight(y->right) + 1);
    return y;
}

int balanceFactor(node *root) {
    if(root == nullptr) return 0;
    return getHeight(root->left) - getHeight(root->right);
}

node *insert(node *root, int x) {
    if(root == nullptr)
        return makeNode(x);
    if(x < root->data)
        root->left = insert(root->left, x);
    else if(x > root->data)
        root->right = insert(root->right, x);
    else
        return root;

    root->height = 1 + findMax(getHeight(root->left), getHeight(root->right));
    int balance = balanceFactor(root);
    if(balance > 1 && x < root->left->data)
        return rotateRight(root);
    if(balance < -1 && x > root->right->data)
        return rotateLeft(root);
    if(balance > 1 && x > root->left->data) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if(balance < -1 && x < root->right->data) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    return root;
}

node *findMin(node *root) {
    node *current = root;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

node *deleteNode(node *root, int x) {
    if(root == nullptr)
        return root;
    if(x < root->data)
        root->left = deleteNode(root->left, x);
    else if(x > root->data)
        root->right = deleteNode(root->right, x);
    else {
        if((root->left == nullptr) || root->right == nullptr) {
            node *tmp = root->left?root->left:root->right;
            if(tmp == nullptr) {
                tmp = root;
                root = nullptr;
            } else {
                *root = *tmp;
                free(tmp);
            }
        } else {
            node *tmp = findMin(root->right);
            root->data = tmp->data;
            root->right = deleteNode(root->right, tmp->data);
        }
    }

    if(root == nullptr)
        return root;
    root->height = 1 + findMax(getHeight(root->left), getHeight(root->right));
    int balance = balanceFactor(root);
    if(balance > 1 && balanceFactor(root->left) >= 0)
        return rotateRight(root);
    if(balance > 1 && balanceFactor(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if(balance < -1 && balanceFactor(root->right) <= 0)
        return rotateLeft(root);
    if(balance < -1 && balanceFactor(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    return root;
}

void NLR(node *root) {
    if(root != nullptr) {
        cout << root->data << " ";
        NLR(root->left);
        NLR(root->right);
    }
}

int main() {
    node *root = nullptr;
    root = insert(root, 10);
    root = insert(root, 32);
    root = insert(root, 14);
    root = insert(root, 13);
    root = insert(root, 45);

    NLR(root);
    root = deleteNode(root, 13);
    NLR(root);
    return 0;
}