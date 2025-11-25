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
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentMap, TreeNode* target) {
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

    public:
    vector<int> distanceK(TreeNode* root , TreeNode* target , int k){
        unordered_map<TreeNode*, TreeNode*> parentMap;
        markParents(root, parentMap , target);
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int curr_level = 0;
        if(k == 0) return {target->val};
        while(!q.empty()){
            int size =q.size();
            
            if(curr_level++ == k) break;
            for(int i = 0 ; i<size ;i++){
                TreeNode* current = q.front();
                q.pop();
                if(current ->left && !visited[current->left]){
                    q.push(current->left);
                    visited[current->left] = true;
                }
                if(current ->right && !visited[current->right]){
                    q.push(current->right);
                    visited[current->right] = true;
                }
                if(parentMap[current] && !visited[parentMap[current]]){
                    q.push(parentMap[current]);
                    visited[parentMap[current]] = true;
                }
            }
        }
        vector<int> result;
        while(!q.empty()){
            result.push_back(q.front()->val);
            q.pop();
        }
        return result;
    }


};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

     // Node with value 5
    TreeNode* target = root->left;
    int k = 2;

    Solution sol;
    vector<int> result = sol.distanceK(root, target, k);

    for (int val : result) {
        cout << val << " ";
    }

    return 0;
    
}