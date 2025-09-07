#include<bits/stdc++.h>
using namespace std;
class node {
public:
    int data;
    node* next;
    node* prev;
    node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
class linklist{
    public:
    node* head;
    node* tail;
    linklist(){
        head = NULL;
        tail = NULL;
    }
    void insert(int val){
        node* newNode = new node(val);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void display(){
        node* curr = head;
        cout << "NULL <-> ";
        while(curr != NULL){
            cout << curr->data << " <-> ";
            curr = curr->next;
        }
        cout << "NULL" << endl;
    }
    
};
int main() {
    linklist ll;
    vector<int> arr = {2, 5, 8, 7 , 78};
    for(int i=0; i<arr.size(); i++){
        ll.insert(arr[i]);
    }
    int val;
    cout<<"Enter a value to insert: ";
    cin>>val;
    ll.insert(val);
    ll.display();
    return 0;
}