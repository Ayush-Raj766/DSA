#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
class Solution {
public:
    int maxDepth(Node* root) {
        if (root == NULL) {
            return 0;
        }
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return max(leftDepth, rightDepth) + 1;
    }

bool isBalanced(Node* root){
    if(root==NULL) return true;
    int leftH = maxDepth(root->left);
    int rightH = maxDepth(root->right);
    if(abs(leftH-rightH)>1) return false;
    return isBalanced(root->left) && isBalanced(root->right);
}
};
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    // Creating an instance of the Solution class
    Solution solution;

    // Checking if the tree is balanced
    if (solution.isBalanced(root)) {
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }

    return 0;
}