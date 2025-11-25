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
    vector<vector<int>> findVertical(Node* root){
        vector<vector<int>> result;
        if(root == nullptr) return result;
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<Node*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            Node* node = p.first;
            int x = p.second.first;
            int y = p.second.second;
            nodes[x][y].insert(node->data);
            if(node->left) q.push({node->left, {x - 1, y + 1}});
            if(node->right) q.push({node->right, {x + 1, y + 1}});
        }
        for(auto p : nodes){
            vector<int> col;
            for(auto q : p.second){
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            result.push_back(col);  
        }
        return result;
    }
};
void printResult(const vector<vector<int>>& result) {
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        }
        cout << endl;
    }

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

    // Get the Vertical traversal
    vector<vector<int>> verticalTraversal =
                    solution.findVertical(root);

    // Print the result
    cout << "Vertical Traversal: ";
    printResult(verticalTraversal);
    return 0;
}