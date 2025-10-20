#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val ; 
    TreeNode* left ;
    TreeNode* right;

    TreeNode(int a){
        val =a;
        left = right=NULL;
    }

};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* node = s.top();
            s.pop();
            result.push_back(node->val);
            if (node->right) s.push(node->right);
            if (node->left) s.push(node->left);
        }
        return result;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Initializing the Solution class
    Solution sol;

    // Getting the preorder traversal
    vector<int> result = sol.preorderTraversal(root);

    // Displaying the preorder traversal result
    cout << "Preorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}