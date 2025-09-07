#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next = NULL;
    node (int val){
        data = val;
        next = NULL;
    }
};

class linkList{
    public:
    node* head;
    linkList(){
        head = NULL;
    }
    void insert(int val){
        node* newNode = new node(val);
        if(head == NULL){
            head = newNode;
        }else{
            node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void deleteTail(){
        if (head == NULL) {   // empty list
        cout << "List is empty\n";
        return;
    }

    if (head->next == NULL) {  // only one node
        delete head;
        head = NULL;
        return;
    }
        node* temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        node* toDelete = temp->next;
        temp->next = NULL;
        delete toDelete;

    }
    void display(){
        node* temp = head;
        while(temp!=NULL){
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    linkList ll;
    int arr[] = {1};
    for(int i = 0; i < 1; i++){
        ll.insert(arr[i]);
    }
    // int val;
    // cin >> val;
    // ll.insert(val);
    ll.display();
    ll.deleteTail();
    ll.display();

    return 0;
}