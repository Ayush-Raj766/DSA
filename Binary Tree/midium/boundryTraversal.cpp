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

    void leftBoundry(Node* root , vector<int>&res){
        Node * curr = root->left;
        while(curr){
            if(!isLeaf(curr)) res.push_back(curr->data);
            if(curr->left) curr= curr->left;
            else curr = curr->right;
        }
    }
    void rightBoundry(Node* root , vector<int>&res){
        Node * curr = root->right;
        vector<int> temp;
        while(curr){
            if(!isLeaf(curr)) temp.push_back(curr->data);
            if(curr->right) curr= curr->right;
            else curr = curr->left;
        }
        for(int i=temp.size()-1;i>=0;i--){
            res.push_back(temp[i]);
        }
    }
    void addLeaf(Node* root , vector<int>&res){
        if(isLeaf(root)){
            res.push_back(root->data);
            return;
        }
        if(root->left) addLeaf(root->left,res);
        if(root->right) addLeaf(root->right,res);
    }
    bool isLeaf(Node* node){
        if(node->left == nullptr && node->right == nullptr) return true;
        return false;
    }
    vector<int> printBoundary(Node* root){
        vector<int> res;
        if(root == nullptr) return res;
        if(!isLeaf(root)) res.push_back(root->data);
        leftBoundry(root,res);
        addLeaf(root,res);
        rightBoundry(root,res);
        return res;
    }
};
void printResult(const vector<int>& result) {
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
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

    // Get the boundary traversal
    vector<int> result = solution.printBoundary(root);

    // Print the result
    cout << "Boundary Traversal: ";
    printResult(result);

    return 0;
}