#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};  
class Solution {
public:
    
    string serialize(TreeNode* root) {
        if (!root) return "#,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    TreeNode* deserializeHelper(queue<string>& node){
        string val = node.front();
        node.pop();
        if(val == "#") return NULL;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserializeHelper(node);
        root->right = deserializeHelper(node);
        return root;

    }

    TreeNode* deserialize(string data) {
        queue<string> nodes;
        stringstream ss(data);
        string token;
        while (getline(ss, token, ',')) {
            nodes.push(token);
    }
    return deserializeHelper(nodes);
    }

};
void inorder(TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}



int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Solution solution;
    cout << "Orignal Tree: ";
    inorder(root);
    cout << endl;

    string serialized = solution.serialize(root);
    cout << "Serialized: " << serialized << endl;

    TreeNode* deserialized = solution.deserialize(serialized);
    cout << "Tree after deserialisation: ";
    inorder(deserialized);
    cout << endl;

    return 0;
}