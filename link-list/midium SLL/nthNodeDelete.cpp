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

Node* DeleteNthNodefromEnd(Node* head , int n){
    Node* temp = head;
    int count = 0;
    while(temp !=NULL){
        temp = temp->next;
        count++;
    }
    int x = count - n;
     if(x<0){
        cout<<"not possible";
     }
     if(x==0){
        Node* toDelete =head;
        head=head->next;
        delete toDelete;
        return head;
     }
    temp = head;
    while(x > 1){
        temp = temp->next;
        x--;
    }
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
    return head;

}
int main() {
       vector<int> arr = {1, 2, 3, 4, 5};
    int N = 3;
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    head->next->next->next->next = new Node(arr[4]);
printLL(head);
    // Delete the Nth node from the end 
    // and print the modified linked list
    head = DeleteNthNodefromEnd(head, N);
    printLL(head);
    return 0;
}