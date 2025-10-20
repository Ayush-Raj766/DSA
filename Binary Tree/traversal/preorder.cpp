#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data; 
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
vector<int> preOrder(Node* root) {
    vector <int>result;
    if(root == nullptr) return result;
    result.push_back(root->data);
    vector<int> left = preOrder(root->left);
    vector<int> right = preOrder(root->right);
    result.insert(result.end(), left.begin(), left.end());
    result.insert(result.end(), right.begin(), right.end());
    return result;
}

int main() {
     Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Getting preorder traversal
    vector<int> result = preOrder(root);

    // Displaying the preorder traversal result
    cout << "Preorder Traversal: ";
    // Output each value in the
    // preorder traversal result
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}