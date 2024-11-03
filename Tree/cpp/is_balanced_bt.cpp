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

int height(struct Node* root) {
    if(root == NULL) return 0;
    int leftH = height(root->left);
    if(leftH == -1) return -1;
    int rightH = height(root->right);
    if(rightH == -1) return -1;
    if(abs(leftH-rightH)>1) return -1;
    return 1 + max(leftH, rightH);
}

int main() {
    struct Node* root = new Node(1);
    root->left = new Node(5);
    root->right = new Node(4);
    root->left->right = new Node(2);
    root->left->left = new Node(3);
    int h = height(root);
    if(h == -1) cout<<"False"<<endl;
    else cout<<"True"<<endl;
}