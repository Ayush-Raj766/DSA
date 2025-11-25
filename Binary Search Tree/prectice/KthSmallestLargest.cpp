#include<bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val = x; 
        left = NULL;
        right = NULL;
    }
};

class Solution{
    public:
    void Small(TreeNode* root , int k , int &count , int &kthSmall){
        if(root == NULL || count >= k) return;

        Small(root->left , k , count , kthSmall);
        count++;

        if(count == k){
            kthSmall = root->val;
            return;
        }
        Small(root->right , k , count , kthSmall);
    }

    public:

    void Large(TreeNode* root , int k , int &count , int &kthLarge){
        if(root == NULL || count >= k) return;

        Large(root->right , k , count , kthLarge);
        count++;

        if(count == k){
            kthLarge = root->val;
            return;
        }
        Large(root->left , k , count , kthLarge);
    }

public:
pair<int , int> findKth(TreeNode* root , int k){
    int kthSmall = INT_MIN;
    int kthLarge = INT_MIN;
    int count = 0;

    Small(root , k , count , kthSmall);
    count = 0;
    Large(root , k , count , kthLarge);
    return make_pair(kthSmall , kthLarge);
}
};

void printInOrder(TreeNode* root) {
    if (!root) return;
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

    // Find the Kth smallest and largest elements
    int k = 3; 
    cout << "k: "<< k <<endl;
    pair<int, int> kthElements = solution.findKth(root, k);

    cout << "Kth smallest element: " << kthElements.first << endl;
    cout << "Kth largest element: " << kthElements.second << endl;

    return 0;
}