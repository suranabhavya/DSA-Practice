#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void post_order(struct Node* root) {
    if(root == NULL) {
        return;
    }
    post_order(root->left);
    post_order(root->right);
    cout<<root->data<<" ";
}

int main() {
    struct Node* root = new Node(1);
    root->left = new Node(5);
    root->right = new Node(4);
    root->left->right = new Node(2);
    post_order(root);
    cout<<endl;
    return 0;
}