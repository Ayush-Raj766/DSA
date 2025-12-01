#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    if (root == NULL) return result;

    vector<int> left = inorderTraversal(root->left);
    result.insert(result.end(), left.begin(), left.end());

    result.push_back(root->val);

    vector<int> right = inorderTraversal(root->right);
    result.insert(result.end(), right.begin(), right.end());

    return result;
}

bool isBST(TreeNode* root) {
    vector<int> inorder = inorderTraversal(root);
    for (size_t i = 1; i < inorder.size(); ++i) {
        if (inorder[i] <= inorder[i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(13);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(2);
    root->left->left->right = new TreeNode(4);
    root->left->right = new TreeNode(6);
    root->left->right->right = new TreeNode(9);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(14);

    isBST(root) ? cout << "The tree is a BST." << endl : cout << "The tree is not a BST." << endl;
    return 0;
}