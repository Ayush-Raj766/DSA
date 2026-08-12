#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int mod = 1e9 + 7;
    int solve(int i, int target , vector<int>&arr , vector<vector<int>>&dp){
        if(i == 0){
        if(target == 0 && arr[0] == 0)
            return 2;

        if(target == 0 || target == arr[0])
            return 1;

        return 0;
    }

        if(dp[i][target] != -1){
            return dp[i][target];
        }
        int notTake = solve(i-1 , target , arr , dp);
        int take = 0 ; 
        if(arr[i] <= target){
            take = solve(i-1 , target - arr[i] , arr , dp);
        }
        return dp[i][target] = (notTake + take) % mod;
    }
    int countPartitions(vector<int>& nums, int d) {
       int n = nums.size();
       int totalSum = accumulate(nums.begin(), nums.end(), 0);
       int target = (totalSum - d) / 2;
       if (totalSum < d || (totalSum - d) % 2 != 0) {
           return 0; 
       }
       vector<vector<int>> dp(n , vector<int>(target+1 , -1));
         return solve(n-1 , target , nums , dp);
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 1, 2, 3};
    int d = 1;
    cout << sol.countPartitions(arr, d) << endl;
    return 0;
}