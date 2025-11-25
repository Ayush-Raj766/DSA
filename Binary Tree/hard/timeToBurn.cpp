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
    void makeParent(TreeNode* root, unordered_map<TreeNode* , TreeNode*>& parentMap) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            if(current->left){
                parentMap[current->left] = current;
                q.push(current->left);
            }
            if(current->right){
                parentMap[current->right] = current;
                q.push(current->right);
            }
        }
    }

    public :
    TreeNode* targetNodeFinder(TreeNode* root , int target){
        if(root == nullptr) return nullptr;
        if(root->val == target) return root;
        TreeNode* leftAns = targetNodeFinder(root->left , target);
        TreeNode* rightAns = targetNodeFinder(root->right , target);
        if(leftAns != nullptr) return leftAns;
        if(rightAns != nullptr) return rightAns;
        return nullptr;
    }

    public:
    int minTime(TreeNode* root, int target) {
        unordered_map<TreeNode* , TreeNode*> parentMap;
        makeParent(root, parentMap);
        unordered_map<TreeNode* , bool> visited;
        queue<TreeNode*> q;
        int time = 0;
        TreeNode* targetNode = targetNodeFinder(root, target);
        q.push(targetNode);
        visited[targetNode] = true;
        while(!q.empty()){
            int size = q.size();

            for(int i = 0 ; i<size ; i++){
                TreeNode* current = q.front();
                q.pop();
                if(current->left && !visited[current->left]){
                    q.push(current->left);
                    visited[current->left] = true;
                }
                if(current->right && !visited[current->right]){
                    q.push(current->right);
                    visited[current->right] = true;
                }
                if(parentMap[current] && !visited[parentMap[current]]){
                    q.push(parentMap[current]);
                    visited[parentMap[current]] = true;
                }
            }
            if(!q.empty()) time++;
        }
        return time;


    }
    
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->left->right = new TreeNode(7);

    // Create solution object
    Solution sol;

    // Set target node to burn from
    int target = 2;

    // Print the minimum time to burn the tree
    cout << "Minimum time to burn the tree: " << sol.minTime(root, target) << endl;
    return 0;
}