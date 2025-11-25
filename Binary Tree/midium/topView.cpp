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
    vector<int> topView(Node* root){
        vector<int> result;
        if(root == nullptr) return result;
        map<int,int> topNode;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            Node* node =p.first;
            int x = p.second;
            if(topNode.find(x) == topNode.end()){
                topNode[x] = node->data;
            }
            if(node->left) q.push({node->left, x-1});
            if(node->right) q.push({node->right, x+1});
        }
        for(auto it: topNode) result.push_back(it.second);
        return result;
    }
};


int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(10);
    root->right->left = new Node(9);

    Solution solution;

    // Get the top view traversal
    vector<int> topView =
                    solution.topView(root);

    // Print the result
    cout << "Top View Traversal: "<< endl;
    for(auto node: topView){
        cout << node << " ";
    }
    return 0;
}