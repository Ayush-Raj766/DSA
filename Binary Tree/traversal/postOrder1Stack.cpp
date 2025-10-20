#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;     
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
vector<int> postOrder(Node* root){
    vector<int> result;
    if(root==NULL) return result;
    stack<Node*> s;
    s.push(root);
    while(!s.empty()){
        Node* node = s.top();
        s.pop();
        result.push_back(node->data);
        if(node->left) s.push(node->left);
        if(node->right) s.push(node->right);
    }
    reverse(result.begin(), result.end());
    return result;

}
void printVector(const vector<int>& vec) {
    for (int val : vec) {
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

    // Getting postorder traversal
    vector<int> result = postOrder(root);

    // Printing the postorder
    // traversal result
    cout << "Postorder traversal: ";
    printVector(result);
    return 0;
}