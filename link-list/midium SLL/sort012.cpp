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
    Node* twoHead = NULL;
    Node* twoTail = NULL;
    Node* oneHead = NULL;
    Node* oneTail = NULL;
    Node* zeroHead = NULL;
    Node* zeroTail = NULL;

    Node* current = head;
    while(current != NULL){
        if(current->data  == 0){
            if(zeroHead == NULL){
                zeroHead = current;
                zeroTail = current;
            }else{
                zeroTail->next = current;
                zeroTail = current;
            }
        }else if(current->data == 1){
            if(oneHead == NULL){
                oneHead = current;
                oneTail = current;
            }else{
                oneTail->next = current;
                oneTail = current;
            }
        }else{
            if(twoHead == NULL){
                twoHead = current;
                twoTail = current;
            }else{
                twoTail->next = current;
                twoTail = current;
            }
        }
        
        current = current->next;
    }

    // Combine the zero, one, and two lists
    if(zeroTail != NULL){
        zeroTail->next = oneHead;
    }
    if(oneTail != NULL){
        oneTail->next = twoHead;
    }
    if(twoTail != NULL){
        twoTail->next = NULL;
    }

    return zeroHead != NULL ? zeroHead : oneHead;
    // return evenHead;
}


int main() {
    Node* head = new Node(1);
    head->next = new Node(0);
    head->next->next = new Node(0);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(2);
    head->next->next->next->next->next->next = new Node(0);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(head);
    head = sagregate(head);
    cout << "Segregated Linked List: ";
    printLinkedList(head);

    return 0;
}