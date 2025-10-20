#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data; 
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
vector<int> postOrder(Node* root) {
    vector <int>result;
    if(root == nullptr) return result;
    vector<int> left = postOrder(root->left);
    result.insert(result.end(), left.begin(), left.end());
    vector<int> right = postOrder(root->right);
    result.insert(result.end(), right.begin(), right.end());
    result.push_back(root->data);
    return result;
}

int main() {
     Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Getting postorder traversal
    vector<int> result = postOrder(root);

    // Displaying the postorder traversal result
    cout << "Postorder Traversal: ";
    // Output each value in the
    // postorder traversal result
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}