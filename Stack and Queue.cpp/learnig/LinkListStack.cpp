#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node (int val){
        data = val;
        next = NULL;
    }

};

class stacklist{
    public:
    node* top ;
    int Size ;
    stacklist(){
        top = NULL;
        Size = 0;
    }

    void Push(int val){
        node* newNode = new node(val);
        if(top == NULL){
            top = newNode;
        }else{
            newNode->next = top;
            top = newNode;

        }
        Size++;
    }

    int Pop(){
        if ( top == NULL){
            cout<<"stack is underFlow";
            return -1;
        }
        int topdata = top->data;
        node* temp = top;
        top= top->next;
        delete temp;
        Size--;
        return topdata;

    }

    int getSize(){
        return Size;
    }
    int Top(){
        return top->data;
    }
};


int main() {
      stacklist st;
       st.Push(10);
    st.Push(20);
    st.Push(30);

    cout << "Top element: " << st.Top() << endl;        // 30
    cout << "Size: " << st.getSize() << endl;          // 3

    cout << "Popped: " << st.Pop() << endl;            // 30
    cout << "Popped: " << st.Pop() << endl;            // 20

    cout << "Top element: " << st.Top() << endl;       // 10
    cout << "Size: " << st.getSize() << endl;          // 1

    cout << "Popped: " << st.Pop() << endl;            // 10
    cout << "Popped: " << st.Pop() << endl;            // Underflow

    return 0;
}