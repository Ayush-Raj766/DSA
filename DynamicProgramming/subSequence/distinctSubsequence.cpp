#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve (int i , int j ,string s, string t , vector<vector<int>> &dp ){
        if(i<0) return 0;
        if(j < 0) return 1;
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i] == t[j]){
            int take = solve(i-1 , j-1 , s ,t,dp);
            int notTake =  solve(i-1 , j ,  s, t, dp);

            return dp[i][j] = take+notTake;
        }
        else{
            return dp[i][j] =  solve(i-1 , j ,  s, t, dp);
        }
    }

    int numDistinct(string s, string t) {
        int n  =  s.size();
        int m = t.size();
        vector<vector<int>>dp(n ,  vector<int>(m , -1));
        return solve(n-1 , m-1 ,  s , t ,  dp);

    }
};

int main() {
    string s = "rabbbit";
    string t = "rabbit";
    Solution sol;
    cout << sol.numDistinct(s, t) << endl;
    
    return 0;
}