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
    int diameterOfBinaryTree(Node* root){
        if(root==NULL) return 0;
        int leftH = maxDepth(root->left);
        int rightH = maxDepth(root->right);
        int currDiameter = leftH + rightH;
        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);
        return max(currDiameter, max(leftDiameter, rightDiameter)); 

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

    // Calculate the diameter of the binary tree
    int diameter = solution.diameterOfBinaryTree(root);

    cout << "The diameter of the binary tree is: " << diameter << endl;
    return 0;
}