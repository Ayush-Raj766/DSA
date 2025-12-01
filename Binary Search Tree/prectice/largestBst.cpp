#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class NodeValue {
public:
    int minNode, maxNode, maxSize;
    NodeValue(int minNode, int maxNode, int maxSize) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;
    }
};

NodeValue getMaxBST(TreeNode* root) {
    if(root == nullptr){
        return NodeValue(INT_MAX , INT_MIN , 0);
        
    }
    NodeValue left = getMaxBST(root->left);
    NodeValue right = getMaxBST(root->right);
    if(left.maxNode < root->val && root->val < right.minNode){
        return NodeValue(min(root->val , left.minNode) , max(root->val , right.maxNode) , left.maxSize + right .maxSize + 1);
    }
    return NodeValue(INT_MIN , INT_MAX , max(left.maxSize , right.maxSize));
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(2);

    NodeValue nodeValue = getMaxBST(root);
    cout << "Size of the largest BST is: " << nodeValue.maxSize << endl;

    return 0;
}