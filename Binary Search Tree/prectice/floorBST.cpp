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
    int findfloor(TreeNode* root , int key){
        if(root == NULL) return -1;

        int floor = -1;
        while(root != NULL){
            if(root->val == key){
                floor = root->val;
                return floor;
            }

            if(key > root->val){
                floor = root->val;
                root = root->right;
            }

            else{
                
                root = root->left;
            }
        }
        return floor;
    }
};
void printInOrder(TreeNode* root) {
    if (root == NULL) return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
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
    
    cout << "Binary Search Tree: "<< endl;
    printInOrder(root);
    cout << endl;

    Solution solution;
    
    // Searching for a value in the BST
    int target = 8;
    int floor = solution.findfloor(root, target);
    
    if(floor != -1){
        cout << "flooring of " << target << " is: " << floor << endl;
    }
    else{
        cout << "No flooring found!";
    }
    return 0;
}