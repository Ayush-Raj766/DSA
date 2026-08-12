#include <bits/stdc++.h>
using namespace std;

// class Solution {
//     public:
//     int solve(string s1, string s2, int i, int j, vector<vector<int>>& dp){
//         if(i < 0 || j < 0) return 0;
//         if(dp[i][j] != 0) return dp[i][j];
//         if(s1[i] == s2[j]) return dp[i][j] = 1 + solve(s1, s2, i-1, j-1, dp);
//         return dp[i][j] =  0;

//     }
//     int largestCommonSubstr(string s1 , string s2){
//         int m = s1.size();
//         int n = s2.size();
//         int ans = 0;
//         vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
//         for(int i = 0; i < m; i++){
//             for(int j = 0; j < n; j++){
//                 ans = max(ans, solve(s1, s2, i, j, dp));
//             }
//         }
//         return ans;
//     }
// };

class Solution
{
public:
    int largestCommonSubstr(string s1, string s2)
    {
        int m = s1.size();
        int n = s2.size();
        int ans = 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    ans = max(ans, dp[i][j]);
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        return ans;
    }
};

    int main()
    {
        string s1 = "abcjklp";
        string s2 = "acjkp";

        // Create an instance of Solution class
        Solution sol;

        // Print the result
        cout << "The Length of Longest Common Substring is " << sol.largestCommonSubstr(s1, s2) << endl;
        return 0;
    }