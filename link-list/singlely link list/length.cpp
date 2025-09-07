#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next =NULL;
    }
};
class linklist{
    public:
    Node* head;
    linklist(){
        head=NULL;
    }

    int length(){
        Node* temp = head;
        int count =0;
        while(temp!=NULL){
            count++;
            temp = temp->next;
        }
        return count;
   }


};

int main() {
    vector<int> arr = {2, 5, 8, 7 , 78};
    
    // Create a linked list
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    head->next->next->next->next = new Node(arr[4]);

    linklist ll;
    ll.head = head;

    cout << "Length of linked list: " << ll.length() << endl;

    return 0;
}