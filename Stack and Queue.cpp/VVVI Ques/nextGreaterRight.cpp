#include<bits/stdc++.h>
using namespace std;

vector<int> countGreaterRight(vector<int>& arr, vector<int>& indices) {
    int n = arr.size();
    vector<int> greaterCount(n, 0);
    stack<int> st;

    for(int i = n-1 ; i>=0 ; i--){
        while(!st.empty()  && arr[i] >= st.top()){
            st.pop();
        }
        greaterCount[i] = st.size();
        st.push(arr[i]);
    }
     vector<int> ans;
    for (int idx : indices) {
        ans.push_back(greaterCount[idx]);
    }
    return ans;
}

int main() {
        vector<int> arr = {5, 2, 6, 1, 7};
    vector<int> queries = {0, 1, 2}; // positions for which we answer

    vector<int> res = countGreaterRight(arr, queries);

    cout << "Results: ";
    for (int x : res) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}