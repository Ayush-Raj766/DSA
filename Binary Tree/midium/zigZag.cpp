#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
class Solution{
    public:
    vector<vector<int>>ZigZagLevelOrder(Node* root){
        vector<vector<int>> result;
        if(root == nullptr) return result;
        queue<Node*> q;
        int count =0;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i =0 ; i<size;i++){
                Node* node = q.front();
                q.pop();
                level.push_back(node->data);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                if (count % 2 != 0) {
            reverse(level.begin(), level.end());
        }
            }
            result.push_back(level);
            count++;
        }
        return result;
    }

};
void printResult(const vector<vector<int>>& result) {
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
     Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution solution;

    // Get the zigzag level order traversal
    vector<vector<int>> result = solution.ZigZagLevelOrder(root);

    // Print the result
    printResult(result);

    return 0;
}