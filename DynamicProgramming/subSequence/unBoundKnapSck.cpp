#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int solve(int i , int w , vector<int> &val , vector<int>&wt , vector<vector<int>>&dp){
        if(i == 0){
            if(wt[0] <= w){
                return (w/wt[0]) * val[0];
            }
            return 0;
        }
        if(dp[i][w] != -1){
            return dp[i][w];
        }
        int notTake = solve(i-1 ,  w , val , wt , dp);
        int take = INT_MIN;
        if(wt[i] <= w){
            take = val[i] + solve(i , w - wt[i] , val , wt , dp);
        }
        return dp[i][w] = max(take , notTake);
    }
    int unboundedKnapsack(int n, int W, vector<int> &val, vector<int> &wt){
        vector<vector<int>> dp(n, vector<int>(W+1, -1));

        return solve(n-1, W, val, wt, dp);
    }
};

int main() {
     vector<int> wt = {2, 4, 6};

    // Initialize item values
    vector<int> val = {5, 11, 13};

    // Weight capacity of the knapsack
    int W = 10;

    // Number of items
    int n = wt.size();

    // Create Solution object
    Solution obj;

    // Output the result
    cout << "The Maximum value of items the thief can steal is " 
         << obj.unboundedKnapsack(n, W, val, wt) << endl;
    return 0;
}