#include<bits/stdc++.h>
using namespace std;

class Queue{

    stack<int> s1 , s2;
    int top;
    public:

    void Push(int n){
      
      for(int i = 0 ;i<s1.size();i++){
        s2.push(s1.top());
        s1.pop();
      }
      s1.push(n);

      for(int i = 0 ;i<s2.size();i++){
        s1.push(s2.top());
        s2.pop();
      }

    }

    int Pop(){
      int x = s1.top();
      s1.pop();
      return x;
    }
    int Top(){
      return s1.top();
    }
    int size(){
      return s1.size();
    }

};

int main() {
    Queue q;
  q.Push(3);
  q.Push(4);
  cout << "The element poped is " << q.Pop() << endl;
  q.Push(5);
  cout << "The top of the queue is " << q.Top() << endl;
  cout << "The size of the queue is " << q.size() << endl;
    return 0;
}