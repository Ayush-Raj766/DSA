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
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev  = nullptr;
    TreeNode* last = nullptr;

    void inorder(TreeNode* root){
        if(root == nullptr) return;

        inorder(root->left);
        if(prev != nullptr && prev->val > root ->val ){
            if(first == nullptr){
                first = prev;
                second = root;

            }
            else{
                last = root;
            }
        }

        prev = root;

        inorder(root->right);
    }


    void recoverTree(TreeNode* root){
        inorder(root);
        if(first && last ){
            swap(first ->val , last->val);
        }
        else if(first && second){
            swap(first->val , second->val);
        }
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(2);

    Solution sol;
    sol.recoverTree(root);
    return 0;
}