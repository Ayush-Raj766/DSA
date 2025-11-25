#include<bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) {
        val = value;
        left = right = nullptr;
    }
};

class Solution {
    public:
    int widthOfBinaryTree(TreeNode* root ){
        if(root == nullptr) return 0;
        unsigned long long maxWidth = 0;
        queue<pair<TreeNode* , unsigned long long>> q;
        q.push({root , 0});
        while(!q.empty()){
            int size = q.size();
            unsigned long long minIndex = q.front().second;
            unsigned long long first=0 , last=0;
            for(int i=0 ; i<size ;i++){
                unsigned long long curIdx = q.front().second - minIndex;
                TreeNode* node = q.front().first;
                q.pop();
                if(i==0) first = curIdx;
                if(i==size-1) last = curIdx;
                if(node->left) q.push({node->left , curIdx*2 + 1});
                if(node->right) q.push({node->right , curIdx*2 + 2});
            }
            maxWidth = max(maxWidth , (last - first + 1));
        }
        return (int)maxWidth;
    }
    
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    // Create solution object
    Solution sol;

    // Call the function and print the result
    cout << "Maximum width: " << sol.widthOfBinaryTree(root ) << endl;

    return 0;
}