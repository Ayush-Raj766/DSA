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
void printLL(Node* head){
    Node* curr = head;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

Node* DeleteNthNodefromEnd(Node* head ){
    Node* fast = head;
    Node* slow = head;
    fast = head->next->next;
        if(head == NULL || head->next == NULL){
            return NULL;
        }
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    Node* toDelete = slow->next;
    slow->next = slow->next->next;
    delete toDelete;
    return head;
}
int main() {
       vector<int> arr = {1, 2, 3, 4, 5 ,6};
    int N = 3;
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    head->next->next->next->next = new Node(arr[4]);
    head->next->next->next->next->next = new Node(arr[5]);
printLL(head);
    // Delete the Nth node from the end 
    // and print the modified linked list
    head = DeleteNthNodefromEnd(head);
    printLL(head);
    return 0;
}