#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

vector<vector<int>> findPairs(Node* head, int target, Node* tail) {
    vector<vector<int>> result;
    Node* left = head;
    Node* right = tail;
    while(left != NULL && right !=NULL && left !=right){
        // if(left->data < right->data){
            int sum = left->data + right->data;
            if(sum == target){
                result.push_back({left->data, right->data});
                left = left->next;
                right = right->prev;
            }
            else if(sum < target){
                left = left->next;
            } else {
                right = right->prev;
            // }
        }
    }
    return result;

}
void printPairs(const vector<vector<int>>& pairs) {
    for (const auto& p : pairs) {
        cout << "(" << p[0] << ", " << p[1] << ") ";
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    Node* n7 = new Node(8);
    Node* tail = new Node(9);

    head->next = n2; n2->prev = head;
    n2->next = n3; n3->prev = n2;
    n3->next = n4; n4->prev = n3;
    n4->next = n5; n5->prev = n4;
    n5->next = n6; n6->prev = n5;
    n6->next = n7; n7->prev = n6;
    n7->next = tail; tail->prev = n7;

    int target = 7;
    vector<vector<int>> res = findPairs(head, target , tail);

    cout << "Pairs with sum = " << target << ": ";
    printPairs(res);
    return 0;
}