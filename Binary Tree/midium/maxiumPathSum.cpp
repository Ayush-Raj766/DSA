#include<bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};
class Solution { 
public:
    int maxSum = INT_MIN;
    int maxPathSumUtil(TreeNode* root){
        if(root == NULL) return 0;
        int leftSum = max(0, maxPathSumUtil(root->left));
        int rightSum = max(0, maxPathSumUtil(root->right));
        maxSum = max(maxSum , leftSum + rightSum + root->val);
        return root->val + max(leftSum , rightSum);
    }

    int maxPathSum(TreeNode* root) {
        maxPathSumUtil(root);
        return maxSum;
    }

};


int main() {
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;
    cout << "Maximum Path Sum: "
         << obj.maxPathSum(root) << endl;
    return 0;
}