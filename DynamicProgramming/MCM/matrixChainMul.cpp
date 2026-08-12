#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int  solve(vector<int>& arr, int i, int j, vector<vector<int>>& dp) {
        if(i == j) return 0;
        int minCost = INT_MAX;

        if(dp[i][j] != INT_MAX) return dp[i][j];

        for(int k = i ; k < j ; k++){
            int cost1 = solve(arr , i , k , dp);
            int cost2 = solve(arr , k + 1 , j, dp);

            int steps = arr[i - 1] * arr[k] * arr[j];
            int totalCost = cost1 + cost2 + steps;
            minCost = min(minCost , totalCost);
        }
        return dp[i][j] = minCost;
    }

    int matrixChainOrder(vector<int>& arr, int i, int j) {

        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        return solve(arr, i, j, dp);
    }
};

int main() {
    Solution sol;
    vector<int> arr = {40, 20, 30, 10, 30}; 
    int n = arr.size();

    cout << "Minimum number of multiplications is: "
         << sol.matrixChainOrder(arr, 1, n - 1) << endl;

    return 0;
}