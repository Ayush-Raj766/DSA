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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;
        stack<TreeNode*> s;
        TreeNode* node = root;
        while (node != nullptr || !s.empty()) {
            while (node != nullptr) {
                s.push(node);
                node = node->left;
            }
            node = s.top();
            s.pop();
            result.push_back(node->val);
            node = node->right;

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
    vector<int> result = sol.inorderTraversal(root);

    // Displaying the preorder traversal result
    cout << "Inorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}