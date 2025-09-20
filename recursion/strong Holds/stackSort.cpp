#include<bits/stdc++.h>
using namespace std;

void insertSortStack(stack<int> &st , int x){
    if(st.empty() || st.top() <= x){
        st.push(x);
        return;
    }
    int temp = st.top();
    st.pop();
    insertSortStack(st, x);
    st.push(temp);
}

void sortStack(stack<int> &st){
    if(st.empty()) return;

    int topval = st.top();
    st.pop();
    sortStack(st);
    insertSortStack(st , topval);
}

int main() {
    stack<int> st;
    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);

    sortStack(st);

    cout << "Sorted stack (top to bottom): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}