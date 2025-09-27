#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    vector<int>nextSmallerElements(vector <int>&num){
        int n =num.size();
        vector <int> ngi (n,-1);
        stack<int>st;
        for(int i=n-1 ; i>=0 ;i--){
            while(!st.empty() && st.top()>=num[i]){
                st.pop();

            }
            if (i < n) {
          if (!st.empty()) ngi[i] = st.top();
        }
        st.push(num[i]);
        }
        return ngi;
    }
};


int main() {
      Solution obj;
  vector < int > v {4, 8, 5, 2, 25};
  vector < int > res = obj.nextSmallerElements(v);
  cout << "The next Smaller elements are" << endl;
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
    return 0;
}