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

int main() {
    struct Node* root = new Node(1);
    root->left = new Node(5);
    root->right = new Node(4);
    root->left->right = new Node(2);
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        struct Node* front = q.front();
        q.pop();
        cout<<front->data<<" ";
        if(front->left != NULL) q.push(front->left);
        if(front->right != NULL) q.push(front->right);
    }
    return 0;
}