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

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
void removeDuplicates(Node* head){
    Node* curr = head;
    Node* dup = curr->next;
    while(dup != NULL){
        if(curr->data == dup->data){
            Node* temp = dup;
            dup = dup->next;

            curr->next = dup;
            if(dup != NULL){
                dup->prev = curr;
            }

            delete temp;
        }
        else{
            curr = dup;
            dup = dup->next;
        }
        dup = curr->next;

    }
}

int main() {
    Node* head = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(2);
    Node* n4 = new Node(3);
    Node* n5 = new Node(4);
    Node* n6 = new Node(4);
    Node* n7 = new Node(5);

    head->next = n2; n2->prev = head;
    n2->next = n3; n3->prev = n2;
    n3->next = n4; n4->prev = n3;
    n4->next = n5; n5->prev = n4;
    n5->next = n6; n6->prev = n5;
    n6->next = n7; n7->prev = n6;

    cout << "Original list: ";
    printList(head);

    removeDuplicates(head);

    cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}