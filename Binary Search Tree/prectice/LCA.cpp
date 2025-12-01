#include<bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* LCA(TreeNode* root , int n1 , int n2){
    if(root == NULL) return NULL;

    if(root->val == n1 || root->val == n2){
        return root;
    }
    if(n1 < root->val && n2 < root->val){
        return LCA(root->left , n1 , n2);
    }
    if(n1 > root->val && n2 > root->val){
        return LCA(root->right , n1 , n2);
    }
    return root;
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
    LCA(root,3,6);
    TreeNode* lca = LCA(root, 3, 6);
    if (lca != NULL) {
        cout << "LCA of 3 and 6 is: " << lca->val << endl;
    } else {
        cout << "LCA not found." << endl;
    }
    return 0;
}