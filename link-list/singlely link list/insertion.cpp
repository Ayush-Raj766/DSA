#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data ;
    node* next;
    node(int val){
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
            newNode->next = head;
            head = newNode;

        }
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
    int arr[] = {1, 2, 3, 4, 5};
    for(int i = 0; i < 5; i++){
        ll.insert(arr[i]);
    }
    int val;
    cin >> val;
    ll.insert(val);
    ll.display();
    return 0;
}