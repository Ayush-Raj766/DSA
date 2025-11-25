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
   void rightViewHelper(Node* root , int level , vector<int> &result){
        if(root == nullptr) return;
        if(level == result.size()){
            result.push_back(root->data);
        }
        rightViewHelper(root->right , level + 1 , result);
        rightViewHelper(root->left , level + 1 , result);
    }

    vector<int> rightsideView(Node* root){
        vector<int> result;
        rightViewHelper(root , 0 , result);
        return result;
    }

    void leftViewHelper(Node* root , int level , vector<int> &result){
        if(root == nullptr) return;
        if(level == result.size()){
            result.push_back(root->data);
        }
        leftViewHelper(root->left , level + 1 , result);
        leftViewHelper(root->right , level + 1 , result);
    }

    vector<int> leftsideView(Node* root){
        vector<int> result;
        leftViewHelper(root , 0 , result);
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

        // Get the Right View traversal
    vector<int> rightView = solution.rightsideView(root);

    // Print the result for Right View
    cout << "Right View Traversal: ";
    for(auto node: rightView){
        cout << node << " ";
    }
    cout << endl;

    // Get the Left View traversal
    vector<int> leftView = solution.leftsideView(root);

    // Print the result for Left View
    cout << "Left View Traversal: ";
    for(auto node: leftView){
        cout << node << " ";
    }
    cout << endl;

    return 0;
}