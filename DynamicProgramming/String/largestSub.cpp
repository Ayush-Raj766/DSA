#include<bits/stdc++.h>
using namespace std;

class Solution {

public:

    int solve(string &s1 , string &s2 , int i , int j , vector<vector<int>> &dp){
        if(i<0 || j <0) return 0;
        if(dp[i][j] != 0) return dp[i][j];
        if(s1[i] == s2[j]) {
            return dp[i][j] = 1 + solve(s1, s2, i-1, j-1, dp);
        }
        return dp[i][j] = max(solve(s1 , s2 , i-1 , j , dp) , solve(s1 , s2 , i , j-1 , dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        return solve(text1, text2, m-1, n-1, dp);
    }
};

int main() {
    string s1 = "abcde";
    string s2 = "ace";

    Solution sol;
    cout << "LCS: " << sol.longestCommonSubsequence(s1, s2) << endl;
    return 0;
}