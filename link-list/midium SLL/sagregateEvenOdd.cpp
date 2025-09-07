#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

void printLinkedList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}
Node* sagregate(Node* head){
    if (head == NULL || head->next == NULL) {
        return head; // No need to segregate if the list is empty or has only one node
    }
    Node* evenHead = NULL;
    Node* evenTail = NULL;
    Node* oddHead = NULL;
    Node* oddTail = NULL;

    Node* current = head;
    while(current != NULL){
        if(current->data % 2 == 0){
            if(evenHead == NULL){
                evenHead = current;
                evenTail = current;
            }else{
                evenTail->next = current;
                evenTail = current;
            }
        }else{
            if(oddHead == NULL){
                oddHead = current;
                oddTail = current;
            }else{
                oddTail->next = current;
                oddTail = current;
            }
        }
        current = current->next;
    }

    // Combine the even and odd lists
    if(evenTail != NULL){
        evenTail->next = oddHead;
    }
    if(oddTail != NULL){
        oddTail->next = NULL;
    }

    return evenHead != NULL ? evenHead : oddHead;
    // return evenHead;
}


int main() {
    Node* head = new Node(1);
    head->next = new Node(8);
    head->next->next = new Node(4);
    head->next->next->next = new Node(11);
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(5);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(head);
    head = sagregate(head);
    cout << "Segregated Linked List: ";
    printLinkedList(head);

    return 0;
}