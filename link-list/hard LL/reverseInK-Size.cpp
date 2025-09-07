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
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
 void reverse(Node* &head , Node* &tail){
        Node* prev = NULL;
        Node* curr = head;
        Node* nxt = NULL;
        Node* stop = tail->next;
        while(curr != stop){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        Node* oldHead = head;
        head=prev;
        tail = oldHead;
    }

Node* kReverse(Node* head , int d){
    // Node* temp = head;
    Node* tail = head;
    int count = 1;

    if(head == NULL){
        return NULL;
    }
    if(tail->next == NULL){
        return head;
    }

    while(tail != NULL){
        
        if(count == d){
            Node* nxt = tail->next;
            reverse(head , tail);
            // temp = tail->next;
            tail->next = kReverse(nxt , d);
            return head;

        }
        else{
            tail = tail->next;
        }
        count++;
        
    }
    return head;
}

int main() {
    Node* head = new Node(5);
    head->next = new Node(4);
    head->next->next = new Node(3);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(9);
    head->next->next->next->next->next = new Node(2);

    cout << "Original Linked List: ";
    printLinkedList(head);

    
    head = kReverse(head, 4);

    cout << "Reversed Linked List: ";
    printLinkedList(head);
    return 0;
}