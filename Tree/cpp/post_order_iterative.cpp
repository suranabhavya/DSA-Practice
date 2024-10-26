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
    struct Node* node = root; 
    while(node!=NULL || !s.empty()) {
        while(node != NULL) {
            s.push(node);
            node = node->left;
        }
        node = 
    }
    cout<<endl;
    return 0;
}