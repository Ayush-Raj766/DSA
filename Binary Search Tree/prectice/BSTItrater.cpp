#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};  

class BSTIterator{
    public:
        stack<Node*> Stack;
        BSTIterator(Node* root) {
            pushAll(root);
        }
        bool hasNext() {
            return !Stack.empty();
        }
        int next() {
            Node* temp = Stack.top();
            Stack.pop();
            if(temp->right){
                pushAll(temp->right);
            }
            return temp->data;
        }

        void pushAll(Node* node){
            while(node != nullptr) {
                Stack.push(node);
                node = node->left;  // Move to the leftmost node
            }
        }

};

int main() {
    Node* root1 = new Node(3);
    root1->left = new Node(1);
    root1->right = new Node(5);
    root1->left->right = new Node(2);
    root1->right->left = new Node(4);
    root1->right->right = new Node(6);
    root1->right->right->right = new Node(7);

    BSTIterator bstIterator(root1);
    while(bstIterator.hasNext()) {
        cout << bstIterator.next() << " ";
    }
    return 0;
}
