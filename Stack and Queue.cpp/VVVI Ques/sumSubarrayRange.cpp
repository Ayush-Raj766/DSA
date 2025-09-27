#include <bits/stdc++.h>
using namespace std;

int sumMinimum(vector<int> &num)
{
    int n = num.size();
    vector<int> nsi(n, -1);
    vector<int>psi(n,-1);
    // vector<int> res(n);
    int ans = 0;
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && num[st.top()] >= num[i])
        {
            st.pop();
        }
        
            if (!st.empty()){
                nsi[i] = st.top()-i;
            }
            else{
                nsi[i]=n-i;
            }
        st.push(i);
    }
    while(!st.empty()){
        st.pop();
    }
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && num[st.top()] >= num[i])
        {
            st.pop();
        }
        
            if (!st.empty()){
                psi[i] = i-st.top();
        }
        else{
            psi[i]=i+1;
        }
        st.push(i);
    }
    while(!st.empty()){
        st.pop();
    }

    vector<int> ngi(n, -1);
    vector<int>pgi(n,-1);
    // vector<int> res(n);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && num[st.top()] <= num[i])
        {
            st.pop();
        }
        
            if (!st.empty()){
                ngi[i] = st.top()-i;
            }
            else{
                ngi[i]=n-i;
            }
        st.push(i);
    }
    while(!st.empty()){
        st.pop();
    }
    
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && num[st.top()] <= num[i])
        {
            st.pop();
        }
        
            if (!st.empty()){
                pgi[i] = i-st.top();
        }
        else{
            pgi[i]=i+1;
        }
        st.push(i);
    }

    for(int i =0 ;i<n ; i++){
        ans += ((num[i]*ngi[i]*pgi[i])-(num[i] * psi[i]*nsi[i]));

    }
    return ans;




}

int main()
{
    vector<int> arr = {1,2,3};
    int res = sumMinimum(arr);
    cout << "The sum of Subarray Minimum =" <<res<< endl;
    
    return 0;
    // return 0;
}