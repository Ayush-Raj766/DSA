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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;
        if(key > root->val){
            root->right =  deleteNode(root->right , key);
        }
        else if 

        (key < root->val){
            root->left = deleteNode(root->left , key);
        }
        else{
            if(root->left ==NULL){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right == NULL){
                TreeNode* temp = root->left ;
                delete root;
                return temp;
            }

            else {
                TreeNode* IP = root->left;
                while(IP->right != NULL){
                    IP = IP->right;
                }
                root->val = IP->val;
                root->left = deleteNode(root->left, IP->val);
            }
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
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    int key = 3;
    root = sol.deleteNode(root, key);

    cout << (searchBST(root, key) ? "false" : "true") << endl; // true if deleted successfully
    return 0;
}