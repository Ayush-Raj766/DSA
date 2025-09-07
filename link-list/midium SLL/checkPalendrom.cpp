#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next =NULL;
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

 Node* reverse(Node* head){
        Node* prev = NULL;
        Node* curr = head;
        Node* nxt = NULL;
        while(curr != NULL){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        head = prev;
        return head;
    }
bool isPalindrome(Node* head){
    Node* first = head;
    Node* second = head;
    int count = 0;
    while(first != NULL){
        first = first->next;
        count++;
    }
    for (int i = 0; i < count / 2; i++) {
        second = second->next;

    }
    if(count % 2 != 0){
        second = second->next;
    }


    Node* secondHalf = reverse(second);


    if(count == 1) return true;
    first = head;
    while(secondHalf != NULL){
        if(first->data != secondHalf->data){
            return false;
        }
        first = first->next;
        secondHalf = secondHalf->next;
    }
    return true;
}

int main() {
     Node* head = new Node(1);
    head->next = new Node(5);
    head->next->next = new Node(2);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(1);
    // head->next->next->next->next->next = new Node(17);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(head);

    // Check if the linked list is a palindrome
    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }
    return 0;
}