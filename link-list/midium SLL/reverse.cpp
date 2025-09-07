#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int val){
        data = val;
        next = NULL;

    }
};
class linklist{
    public:
    node* head;
    linklist(){
        head = NULL;
    }
    void insert(int val){
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
    void display(){
        node* temp = head;
        while(temp != NULL){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    void reverse(){
        node* prev = NULL;
        node* curt = head;
        node* nxt = NULL;
        while(curt != NULL){
            nxt = curt->next;
            curt->next = prev;
            prev = curt;
            curt = nxt;
        }
        head = prev;
    }
};

int main() {
    linklist ll;
    vector<int> arr = {1, 2, 3, 4, 5 ,7};
    for(int i = 0; i < arr.size(); i++){
        ll.insert(arr[i]);
    }
    ll.display();
    ll.reverse();
    ll.display();
    return 0;
}