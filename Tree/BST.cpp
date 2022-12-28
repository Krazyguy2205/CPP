#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *left;
    node *right;
};

node *makeNode(int x) {
    node *newNode = new node;
    newNode->data = x;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

node *insert(node *root, int x) {
    if(root == nullptr)
        return makeNode(x);
    if(root->data > x) {
        root->left = insert(root->left, x);
    } else {
        root->right = insert(root->right, x);
    }
    return root;
}

node *minNode(node *root) {
    node *current = root;
    while(current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

node *deleteNode(node *root, int x) {
    if(root == nullptr) return root;
    if(x < root->data)
        root->left = deleteNode(root->left, x);
    else if(x > root->data)
        root->right = deleteNode(root->right, x);
    else {
        if(root->left == nullptr) {
            node *tmp = root->right;
            free(root);
            return tmp;
        } else if(root->right == nullptr) {
            node *tmp = root->left;
            free(root);
            return tmp;
        }
        node *tmp = minNode(root->right);
        root->data = tmp->data;
        root->right = deleteNode(root->right, tmp->data);
    }
    return root;
}

void LNR(node *root) {
    if(root != nullptr) {
        LNR(root->left);
        cout << root->data << " ";
        LNR(root->right);
    }
}

int main() {
    node *root = nullptr;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 4);

    LNR(root);
    cout << endl;
}
