#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int findIndex(vector<int>& inorder, int val, int start, int end) {
        for(int i = start; i <= end; i++) {
            if(inorder[i] == val) {
                return i;
            }
        }
        return -1; 
    }

    public:
    TreeNode* buildTreeHelper( vector<int>& inorder, vector<int>& postorder, int start, int end , int& postIndex) {
        if (start > end) return NULL;

        // Get current root value and move preorder index
        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        // Find the root in inorder to split left and right subtrees
        int index = findIndex(inorder, rootVal, start, end);

        // Build left and right subtrees recursively
        root->right = buildTreeHelper(inorder, postorder, index + 1, end, postIndex);
        root->left = buildTreeHelper(inorder, postorder, start, index - 1 , postIndex);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int start = 0;
        int end = inorder.size() - 1;
        int postIndex = end; // Initialize postIndex before starting the recursion
        return buildTreeHelper(inorder, postorder, start, end, postIndex);
    }


};

void printInorder(TreeNode* root) {
    if (root == NULL) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}
void printVector(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;   
}

int main() {
    vector<int> inorder = {40, 20, 50, 10, 60, 30};
    vector<int> postorder = {40, 50, 20, 60, 30, 10};

    // Display the input vectors
    cout << "Inorder Vector: ";
    printVector(inorder);

    cout << "Postorder Vector: ";
    printVector(postorder);

    Solution sol;

    // Build the binary tree and
    // print its inorder traversal
    TreeNode* root = sol.buildTree(inorder, postorder);

    cout << "Inorder of Unique Binary Tree Created: " << endl;
    printInorder(root);
    cout << endl;

    return 0;
}