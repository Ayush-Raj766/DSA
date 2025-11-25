#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) {
        val = value;
        left = right = nullptr;
    }
};

class Solution{
    public:
    int countNodes(TreeNode* root){
        
        if(root == nullptr) {
            return 0;
        }

        int leftHight = 0;
        TreeNode* left= root;
        while(left){
            leftHight++;
            left = left->left;
        }
        int rightHight = 0;
        TreeNode* right = root;
        while(right){
            rightHight++;
            right = right->right;   
        }

        if (leftHight == rightHight){
            return pow(2, leftHight) - 1;

        } else {
            return 1 + countNodes(root->left) + countNodes(root->right);

        }

    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    Solution sol;

    // Call the countNodes function
    int totalNodes = sol.countNodes(root);

    // Print the result
    cout << "Total number of nodes in the Complete Binary Tree: "
            << totalNodes << endl;

    return 0;
}