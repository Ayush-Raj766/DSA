#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};
void printLinkedList(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
 Node* getMiddle(Node* head) {
        Node* slow = head;
        Node* fast = head->next;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* mid = slow->next;
        slow->next = NULL; // Split the list into two halves
        // cout << "Middle Element: " << mid->data << endl;
        return mid;
    }
Node* merge(Node* left, Node* right) {
    if (left == NULL) return right;
    if (right == NULL) return left;

    Node* marged = NULL;
    if(left->data < right->data){
        marged = left;
        marged->next = merge(left->next , right);
    }
    else{
        marged = right;
        marged->next = merge(left , right->next);
    }
    return marged;
}
Node* sortLL(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* mid = getMiddle(head);
    Node* left = sortLL(head);
    Node* right = sortLL(mid);
    return merge(left, right);
}
int main() {
        Node* head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(5);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(1);

    cout << "Original Linked List: ";
    printLinkedList(head);

    // Sort the linked list
    head = sortLL(head);

    cout << "Sorted Linked List: ";
    printLinkedList(head);
    return 0;
}