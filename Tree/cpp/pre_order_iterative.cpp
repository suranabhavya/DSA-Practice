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
    stack<Node*> s;
    s.push(root);
    while(!s.empty()) {
        Node* front = s.top();
        s.pop();
        cout<<front->data<<" ";
        if(front->right != NULL) s.push(front->right);
        if(front->left != NULL) s.push(front->left);
    }
    cout<<endl;
    return 0;
}