#include<bits/stdc++.h>
using namespace std;
vector<int> calculateSpan(vector<int> &arr){
    int n = arr.size();
    vector <int> pgi (n);
    stack <int> st;
    for(int i =0;i<n;i++){
        while(!st.empty() && arr[st.top()] <=arr[i]){
            st.pop();
        }
        if(st.empty()){
            pgi[i] = i+1;
        }
        else{
            pgi[i]=i-st.top();
        }
        st.push(i);
    }
    return pgi;
}

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter stock prices: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> result = calculateSpan(arr);

    cout << "Stock span for each day: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}