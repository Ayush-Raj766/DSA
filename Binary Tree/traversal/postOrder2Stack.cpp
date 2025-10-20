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
    vector<int>result;
    if(root==NULL) return result;
    stack<Node*>s1,s2;
    s1.push(root);
    while(!s1.empty()){
        Node* node = s1.top();
        s1.pop();
        s2.push(node);
        if(node->left) s1.push(node->left);
        if(node->right) s1.push(node->right);
    }
    while(!s2.empty()){
        result.push_back(s2.top()->data);
        s2.pop();
    }
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