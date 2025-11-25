#include<bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) {
        val = value;
        left = right = nullptr;
    }
};

class Solution {
    public:
    TreeNode* lowestCommonAncestor(TreeNode* root , int x , int y){
        if(root == nullptr) return nullptr;
        if(root->val == x || root->val == y) return root;
        TreeNode * leftAns = lowestCommonAncestor(root->left , x , y);
        TreeNode * rightAns = lowestCommonAncestor(root->right , x , y);
        if(leftAns == nullptr) return rightAns;
        if(rightAns == nullptr) return leftAns;
        return root;
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

    int x = 5, y = 1;
    TreeNode* ans = sol.lowestCommonAncestor(root, x, y);

    cout << "Lowest Common Ancestor of " << x << " and " << y << " is: " 
         << ans->val << endl;

    x = 6, y = 4;
    ans = sol.lowestCommonAncestor(root, x, y);
    cout << "Lowest Common Ancestor of " << x << " and " << y << " is: " 
         << ans->val << endl;

    x = 7, y = 8;
    ans = sol.lowestCommonAncestor(root, x, y);
    cout << "Lowest Common Ancestor of " << x << " and " << y << " is: " 
         << ans->val << endl;
    return 0;
}