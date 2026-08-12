#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int matrixMultiplication(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        for(int i = 1 ; i < n ; i++){
            dp[i][i] = 0;
        }

        for(int i = n-1 ; i >  0 ;  i-- ){
            for(int j = i+1 ;j < n ; j++){
                int minCost = INT_MAX;
                for(int k = i ; k<j ; k++){
                    int steps = nums[i-1] * nums[k] * nums[j];
                    int totalCost = dp[i][k] + dp[k+1][j] + steps;
                    minCost = min(minCost , totalCost);
                }
                dp[i][j] = minCost;
            }
        }
        return dp[1][n-1];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10, 15, 20, 25};
    // Output should be 8000
    cout << sol.matrixMultiplication(nums) << endl; 
    return 0;
}