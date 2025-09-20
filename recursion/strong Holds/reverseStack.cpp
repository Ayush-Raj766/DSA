#include<bits/stdc++.h>
using namespace std;

void inputStack(stack<int> &st , int x){
    if(st.empty()){
        st.push(x);
        return;
    }
    int temp = st.top();
    st.pop();
    inputStack(st, x);
    st.push(temp);
}

void reverseStack(stack<int> &st){
    if(st.empty()) return;
    int topval = st.top();
    // cout << topval << " ";
    st.pop();
    reverseStack(st);
    inputStack(st, topval);
}

int main() {
    stack<int> st;
    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);
    st.push(14);
    st.push(5);
    st.push(8);
    cout << "reverse stack: ";
    reverseStack(st);
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}