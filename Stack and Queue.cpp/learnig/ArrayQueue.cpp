#include<bits/stdc++.h>
using namespace std;
class Queue{
    int size;
    int *arr;
    int front;
    int back;

    public:
    Queue(int n){
        size = n;
        arr = new int[size];
        front =0;
        back =-1;
    }
    void push(int n){
        back ++;
        arr[back]=n;
    }
    int pop(){
        int val = arr[front];
        front ++;
        return val;
    }
    int top(){
        return arr[front];
    }
    int Size(){
        int res = (back - front )+1 ;
        return res;
    }

};


int main() {
    Queue q(6);
  q.push(4);
  q.push(14);
  q.push(24);
  q.push(34);
  cout << "The peek of the queue before deleting any element " << q.top() << endl;
  cout << "The size of the queue before deletion " << q.Size() << endl;
  cout << "The first element to be deleted " << q.pop() << endl;
  cout << "The peek of the queue after deleting an element " << q.top() << endl;
  cout << "The size of the queue after deleting an element " << q.Size() << endl;
    return 0;
}