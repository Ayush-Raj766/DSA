#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* bstFromPreorderUtil(vector<int>& preorder, int& index, int bound) {
    if(preorder.size()==index || preorder[index] > bound) {
        return NULL;
    }
    TreeNode* root = new TreeNode(preorder[index]);
    index++;
    root->left = bstFromPreorderUtil(preorder, index, root->val);
    root->right = bstFromPreorderUtil(preorder, index, bound);
    return root;
}

void inorderTraversal(TreeNode* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    vector <int>preorder ={8, 5, 1, 7, 10, 12};
    int index = 0;
    TreeNode* root = bstFromPreorderUtil(preorder, index , INT_MAX);
    inorderTraversal(root);
    return 0;
}