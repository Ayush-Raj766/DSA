#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value){
        val = value;
        left = right = NULL;
    }
};

class Solution { 
public:

    pair<TreeNode* , int> dfs(TreeNode* root){
        if(root == NULL){
            return {NULL, 0};
        }

        pair<TreeNode* , int> left = dfs(root->left);
        pair<TreeNode* , int> right = dfs(root->right);

        if(left.second > right.second){
            return {left.first, left.second + 1};
        }
        else if(right.second > left.second){
            return {right.first, right.second + 1};
        }
        else{
            return {root, left.second + 1};
        }    

    }

     TreeNode* subtreeWithAllDeepest(TreeNode* root) {
       
        pair<TreeNode* , int> result = dfs(root);
        return result.first;
    }
};
int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    Solution sol;
    TreeNode* subtreeRoot = sol.subtreeWithAllDeepest(root);
    cout << "The value of the subtree root with all deepest nodes is: " << subtreeRoot->val << endl;

    return 0;
}