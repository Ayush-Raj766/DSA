#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:

int largestRectangleArea(vector <int> &num){
    int n = num.size();
    vector<int> nsi(n, -1);
    vector<int>psi(n,-1);
    int res=0;
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
    for(int i  = 0 ;i<n;i++){
        int temp = 0 ;
        temp = num[i] * (nsi[i] + psi[i]-1);
        res = max(res, temp);

    }
    return res;
}
};

int main() {
    vector < int > histo = {2, 1, 5, 6, 2, 3, 1};
  Solution obj;
  cout << "The largest area in the histogram is " << obj.largestRectangleArea(histo) << endl;
  return 0;
    
}