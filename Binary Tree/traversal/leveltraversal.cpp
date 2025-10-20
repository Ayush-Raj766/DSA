#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int val ; 
    TreeNode* left ;
    TreeNode* right;

    TreeNode(int a){
        val =a;
        left = right=NULL;
    }

};
class Solution{
    public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr) return result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            result.push_back(level);
        }
        return result;
    }
};
void printVector(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}


int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Create an instance
    // of the Solution class
    Solution solution; 
    // Perform level-order traversal
    vector<vector<int>> result = solution.levelOrder(root); 

    cout << "Level Order Traversal of Tree: "<< endl;

    // Printing the level order traversal result
    for (const vector<int>& level : result) {
        printVector(level);
    }
    return 0;
}