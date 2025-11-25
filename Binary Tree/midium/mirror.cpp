#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution{
    public:
    bool isMirror(Node* leftVal , Node* rightVal){
        if(!leftVal && !rightVal) return true;
        if(!leftVal || !rightVal) return false;

        return (leftVal->data == rightVal->data) && isMirror(leftVal->left , rightVal->right) && isMirror(leftVal->right , rightVal->left);
    }

    bool isSymmetric(Node* root){
        if(root == nullptr) return true;
        return isMirror(root->left , root->right);
    }
};
void printInorder(Node* root) {
    if (root == nullptr) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->right->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);

    Solution solution;
    
    cout << "Binary Tree (Inorder): ";
    printInorder(root);
    cout << endl;

    bool res;
    res = solution.isSymmetric(root);
    
    if(res){
        cout << "This Tree is Symmetrical" << endl;
    }
    else{
        cout << "This Tree is NOT Symmetrical" << endl;
    }
    return 0;
}