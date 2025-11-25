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
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int start, int end , int& preIndex) {
        if (start > end) return NULL;

        // Get current root value and move preorder index
        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        // Find the root in inorder to split left and right subtrees
        int index = findIndex(inorder, rootVal, start, end);

        // Build left and right subtrees recursively
        root->left = buildTreeHelper(preorder, inorder, start, index - 1 , preIndex);
        root->right = buildTreeHelper(preorder, inorder, index + 1, end, preIndex);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int start = 0;
        int end = inorder.size() - 1;
        int preIndex = 0; // Initialize preIndex before starting the recursion
        return buildTreeHelper(preorder, inorder, start, end, preIndex);
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
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> preorder = {3, 9, 20, 15, 7};
    
    cout << "Inorder Vector: ";
    printVector(inorder);
    
    cout << "Preorder Vector: ";
    printVector(preorder);
    
    Solution sol;


    TreeNode* root = sol.buildTree(preorder, inorder );
    
    cout << "Inorder of Unique Binary Tree Created: "<< endl;
    printInorder(root);
    cout << endl;

    return 0;
}