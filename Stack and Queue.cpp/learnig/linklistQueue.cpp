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
class Queuelist{
    public:
    node* front ;
    node* back ;
    int Size;

    Queuelist(){
        front = NULL;
        back = NULL;
        Size = 0;
    }

    void Push(int n){
        node* newnode = new node(n);
        if(back == NULL && front ==NULL){
            front = back = newnode;
        }
        else{
            back->next = newnode;
            back = newnode ;
        }
        Size++;
    }
    int Pop(){
        int frontData = front->data;
        node* toDelete = back;
        front = front->next;
        delete toDelete;
        Size--;
        return frontData;
    }
    int Top(){
         if (front == NULL) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return front->data;
    
    }
    int getSize(){
        return Size;
    }
};


int main() {
     Queuelist q;

    q.Push(10);
    q.Push(20);
    q.Push(30);

    cout << "Front element: " << q.Top() << endl; // 10
    cout << "Popped: " << q.Pop() << endl;       // 10
    cout << "Front element: " << q.Top() << endl; // 20
    cout << "Size: " << q.getSize() << endl;      // 2

    return 0;
}