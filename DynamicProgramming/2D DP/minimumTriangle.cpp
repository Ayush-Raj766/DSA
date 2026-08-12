#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i , int j , vector<vector<int>>& triangle , vector<vector<int>>& dp){
        if(i == triangle.size() - 1){
            return triangle[i][j];
        }
       
        if(dp[i][j] != INT_MAX) return dp[i][j];

        int r = solve(i+1 ,  j+1 ,  triangle , dp) + triangle[i][j];
        int l =  solve(i+1 , j  ,  triangle , dp) + triangle[i][j];
        
        return dp[i][j] = min(l,r);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n , vector<int>(n , INT_MAX));
        return solve(0 , 0 , triangle , dp);
        
    }
};

int main() {
    Solution sol;
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << sol.minimumTotal(triangle) << endl;
    return 0;
}