#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:

    int solve(int i , int n , vector<int>&price , vector<vector<int>>&dp){
        if(i == 0){
            return n*price[0];
        }

        if(dp[i][n] != 0){
            return dp[i][n];
        }
        int notTake = solve(i-1 , n , price , dp);
        int take = INT_MIN;
        if(i <= n){
            take = price[i-1] + solve(i , n - i , price , dp);
        }
        return dp[i][n] = max(take , notTake);
    }
    int rodCutting(vector<int> &price , int n){
        vector<vector<int>>dp(n , vector<int>(n+1 , 0));
        return solve(n-1 , n , price , dp);

    }
};

int main() {
      int n = 8;

    // Price list where price[i] is the value of rod of length i+1
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};

    // Create object of Solution class
    Solution obj;

    // Call rodCutting function and print the result
    int maxValue = obj.rodCutting(price, n);
    cout << "The maximum obtainable value is: " << maxValue << endl;
    return 0;
}