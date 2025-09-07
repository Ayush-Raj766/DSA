#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data = val;
        next =NULL;
    }
};

class linklist{
    public:
    node* head;
    linklist(){
        head = NULL;
    }
    void insert(int val){
        node* newnode = new node(val);
        if(head == NULL){
            head = newnode;
            return;
        }
        else{
            node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next=newnode;
        }
    }
    int middle (){
        node* fast=head;
        node* slow = head;
    
        while(fast != NULL && fast->next != NULL){
           fast = fast->next->next;
           slow = slow->next;
        }
        return slow->data;
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
    linklist ll;
    vector<int> arr = {1, 2, 3, 4, 5 ,7};
    for(int i = 0; i < arr.size(); i++){
        ll.insert(arr[i]);
    }
    // int val;
    // cin >> val;
    // ll.insert(val);
    ll.display();
    cout<<"result: "<<ll.middle()<<endl;
    return 0;
}