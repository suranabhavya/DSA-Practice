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

int max_depth(struct Node* root) {
    if(root == NULL) return 0;
    return 1 + max(max_depth(root->left), max_depth(root->right));
}

int main() {
    struct Node* root = new Node(1);
    root->left = new Node(5);
    root->right = new Node(4);
    root->left->right = new Node(2);
    root->left->right->left = new Node(4);
    cout<<max_depth(root)<<endl;
}