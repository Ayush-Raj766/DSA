#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int num;
    node* next;
    node(int val){
        num = val;
        next = NULL;
    }
};

void insertNode(node*& head, int val) {
    if (head == NULL) {
        head = new node(val);
        return;
    }
    node* curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new node(val);
}

void printList(node* head) {
    while (head != NULL) {
        cout << head->num << " ";
        head = head->next;
    }
    cout << endl;
}

int getDiffrence(node* head1 , node* head2){
    int len1 = 0 ; 
    int len2 = 0;
    while(head1 != NULL){
        len1++;
        head1 = head1->next;
    }
    while(head2 != NULL){
        len2++;
        head2 = head2->next;
    }
    return (len1 - len2);
}

node* intersectionPresent(node* head1, node* head2) {
    int diff = getDiffrence(head1 , head2);
    if(diff > 0){
        while(diff-- != 0){
            head1 = head1->next;
        }
    }
    else{
        while(diff++ != 0 ){
            head2 = head2->next;
        }
    }
    while(head1 != NULL){
        if(head1 == head2) return head1;
        head1 = head1->next;
        head2 = head2->next;
    }
    return head1; // No intersection point found
}

int main() {
     node* head = NULL;
    insertNode(head,1);
    insertNode(head,3);
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,4);
    node* head1 = head;
    head = head->next->next->next;
    node* headSec = NULL;
    insertNode(headSec,3);
    node* head2 = headSec;
    headSec->next = head;
    //printing of the lists
    cout<<"List1: "; printList(head1);
    cout<<"List2: "; printList(head2);
    //checking if intersection is present
    node* answerNode = intersectionPresent(head1,head2);
    if(answerNode == NULL )
    cout<<"No intersection\n";
    else
    cout<<"The intersection point is "<<answerNode->num<<endl;
    return 0;
}