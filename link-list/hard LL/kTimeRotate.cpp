#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};
void insertNode(node* &head , int val){
    node* n = new node(val);
    if(head == NULL){
        head = n;
        return;
    }
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}
void printList(node* head){
    node* temp = head;
    while(temp != NULL){
        cout << temp->data << " -> ";   
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
node* rotateRight(node* head , int k){ 
    node* temp = head;
    
    int count = 1;
    if (!head || !head->next ) return head;
    
    while(temp->next->next != NULL){
        temp = temp->next;
        count++;
    }
    int len = k % (count+1); // effective rotations needed
    node* last = temp->next;   // last node
    temp->next = NULL;         // break link
    last->next = head;         // last points to old head
    head = last;               // update new head
    if(len > 0)
        head = rotateRight(head , len - 1); // recur for k-1 times

    return head;
}

int main() {
        node* head = NULL;
    //inserting Node
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,3);
    insertNode(head,4);
    insertNode(head,5);
    
    cout<<"Original list: ";
    printList(head);
    
    int k = 7;
    node* newHead = rotateRight(head, k);//calling function for rotating right of
    // the nodes by k times
    
    cout<<"After "<<k<<" iterations: ";
    printList(newHead);//list after rotating nodes
    return 0;
}