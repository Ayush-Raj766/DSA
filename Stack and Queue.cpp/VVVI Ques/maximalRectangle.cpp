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

int maximalRectangle(vector<vector<int>>& matrix){
    int maxArea = 0;
    if(matrix.empty() || matrix[0].empty()) return 0;
    int m =  matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> ps(m, vector<int>(n, 0));
    for(int j = 0 ; j <n ; j++){
        int sum =0;
        for(int i =0; i< m; i++){
            sum += matrix[i][j];
            if(matrix[i][j] == 0){
                sum = 0;
            }
            ps[i][j]=sum;
        }
    }
    for(int i =0; i<m ;i++){
        maxArea = max(maxArea , largestRectangleArea(ps[i]));
    }

    return maxArea;
    
}
};

int main() {
   vector<vector<int>> matrix = {
        {1, 0, 1, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0}
    };

    Solution obj;
    cout << "The largest rectangle containing only 1's has area: "
         << obj.maximalRectangle(matrix) << endl;

    return 0;
}