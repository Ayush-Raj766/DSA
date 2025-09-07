#include<bits/stdc++.h>
using namespace std;

class Node{
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

void printList(Node* head) {
    Node* curr = head;
    cout << "NULL <-> ";
    while(curr != NULL){
        cout << curr->data << " <-> ";
        curr = curr->next;
        }
        cout << "NULL" << endl;
    }
 
Node* deleteTarget(Node* head , int x){
    Node* curr = head;
    while(curr != NULL){
        if(curr->data == x){
            Node* toDelete = curr;
            if(curr->prev != NULL){
                curr->prev->next = curr->next;
            } else {
                head = curr->next; // Update head if the first node is to be deleted
            }
            if(curr->next != NULL){
                curr->next->prev = curr->prev;
            }
            curr = curr->next; // Move to the next node before deleting
            delete toDelete; // Free memory
        } else {
            curr = curr->next; // Move to the next node
        }
    }
    return head;
}

int main() {
    Node* head = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(2);
    Node* n5 = new Node(4);
    Node* n6 = new Node(2);
    Node* n7 = new Node(5);

    // Linking nodes
    head->next = n2;
    n2->prev = head;

    n2->next = n3;
    n3->prev = n2;

    n3->next = n4;
    n4->prev = n3;

    n4->next = n5;
    n5->prev = n4;

    n5->next = n6;
    n6->prev = n5;

    n6->next = n7;
    n7->prev = n6;

    cout << "Original list: ";
    printList(head);

    int target = 2;
    head = deleteTarget(head, target);

    cout << "List after deleting " << target << ": ";
    printList(head);
    return 0;
}