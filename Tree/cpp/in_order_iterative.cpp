// #include<bits/stdc++.h>
// using namespace std;

// struct Node {
//     int data;
//     struct Node* left;
//     struct Node* right;

//     Node(int val) {
//         data = val;
//         left = NULL;
//         right = NULL;
//     }
// };

// int main() {
//     struct Node* root = new Node(1);
//     root->left = new Node(5);
//     root->right = new Node(4);
//     root->left->right = new Node(2);
//     stack<Node*> s;
//     struct Node* node = root;
//     while(true) {
//         if(node != NULL) {
//             s.push(node);
//             node = node->left;
//         }
//         else {
//             if(s.empty() == true) break;
//             node = s.top();
//             s.pop();
//             cout<<node->data<<" ";
//             node = node->right;
//         }
//     }
//     cout<<endl;
//     return 0;
// }



#include <bits/stdc++.h>
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

    while (node != NULL || !s.empty()) {
        // Traverse left subtree
        while (node != NULL) {
            s.push(node);
            node = node->left;
        }

        // Process the node
        node = s.top();
        s.pop();
        cout << node->data << " ";

        // Traverse right subtree
        node = node->right;
    }

    cout << endl;
    return 0;
}