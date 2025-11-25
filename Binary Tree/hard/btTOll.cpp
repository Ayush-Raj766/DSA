#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:

    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
    TreeNode* nextRight = NULL;
    void flatten (TreeNode* root){
        if(root == NULL) return;
        flatten(root->right);
        flatten(root->left);
        root->left = NULL;
        root->right = nextRight;
        nextRight = root;
    }
};

void printPreorder(TreeNode* root) {
    if (root == NULL) return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}
    void printFlattenTree(TreeNode* root) {
    while (root != NULL) {
        cout << root->val << " ";
        root = root->right;
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->left = new TreeNode(8);

    Solution sol;
    
    cout << "Binary Tree Preorder: ";
    printPreorder(root);
    cout << endl;
    
    sol.flatten(root);
    
    cout << "Binary Tree After Flatten: ";
    printFlattenTree(root);
    cout << endl;
    return 0;
}