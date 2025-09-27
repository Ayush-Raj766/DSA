#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    vector<int>nextGreaterElements(vector <int>&num){
        int n =num.size();
        vector <int> ngi (n,-1);
        stack<int>st;
        for(int i=2*n - 1 ; i>=0 ;i--){
            while(!st.empty() && st.top()<=num[i%n]){
                st.pop();

            }
            if (i < n) {
          if (!st.empty()) ngi[i] = st.top();
        }
        st.push(num[i % n]);
        }
        return ngi;
    }
};


int main() {
      Solution obj;
  vector < int > v {5,7,1,2,6,0};
  vector < int > res = obj.nextGreaterElements(v);
  cout << "The next greater elements are" << endl;
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
    return 0;
}