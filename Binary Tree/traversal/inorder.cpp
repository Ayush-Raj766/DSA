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
vector<int> inOrder(Node* root) {
    vector <int>result;
    if(root == nullptr) return result;
    vector<int> left = inOrder(root->left);
    result.insert(result.end(), left.begin(), left.end());
    result.push_back(root->data);
    vector<int> right = inOrder(root->right);
    result.insert(result.end(), right.begin(), right.end());
    return result;
}

int main() {
         Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Getting inorder traversal
    vector<int> result = inOrder(root);

    // Displaying the inorder traversal result
    cout << "Inorder Traversal: ";
    // Output each value in the
    // inorder traversal result
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}