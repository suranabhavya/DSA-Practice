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

int diameter(struct Node* root, int& maxi) {
    if(root == NULL) return 0;
    int lh = diameter(root->left, maxi);
    int rh = diameter(root->right, maxi);
    maxi = max(maxi, lh + rh);
    return 1 + max(lh, rh);
}

int main() {
    struct Node* root = new Node(1);
    root->left = new Node(5);
    root->right = new Node(4);
    root->right->right = new Node(6);
    root->left->right = new Node(2);
    root->left->right->left = new Node(4);
    int maxi = INT_MIN;
    int height = diameter(root, maxi);
    cout<<maxi<<endl;
}