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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            return new TreeNode(val);
        }
        if(val>root->val){
            root->right =  insertIntoBST(root->right , val);
        }
        else{
            root->left = insertIntoBST(root->left , val);
        }
        return root;
    }
};
bool searchBST(TreeNode* root, int val) {
    if (!root) return false;
    if (root->val == val) return true;
    if (val < root->val) return searchBST(root->left, val);
    return searchBST(root->right, val);
}

int main() {
     Solution sol;
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    int val = 5;
    root = sol.insertIntoBST(root, val);

    cout << (searchBST(root, val) ? "true" : "false") << endl;
    return 0;
}