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
    vector<int> solve(TreeNode* root ,int x) {
        vector<int> path;
        return findPath(root , x , path);
    }
    vector<int> findPath(TreeNode* root ,int x , vector<int>& path) {
        if(root == nullptr) return {};
        path.push_back(root->val);
        if(root->val == x) return path;
        vector<int> leftPath = findPath(root->left , x , path);
        if (!leftPath.empty()) 
            return leftPath;
        vector<int> rightPath = findPath(root->right , x , path);
        if (!rightPath.empty()) 
            return rightPath;
        path.pop_back();
        return {};
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    // Create an instance of the solution class
    Solution sol;

    // Value of the target node
    int targetLeafValue = 7;

    // Get the path from root to the target node
    vector<int> path = sol.solve(root, targetLeafValue );

    // Print the path
    cout << "Path from root to node with value ";
    cout << targetLeafValue << ": ";

    for (int i = 0; i < path.size(); ++i) {
        cout << path[i];
        if (i < path.size() - 1) {
            cout << " -> ";
        }
    }
    return 0;
}