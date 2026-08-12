#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
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
        return dp[i][target] = notTake + take;
    }
    int countSubsets(vector<int>& nums,int target) {

        int n = nums.size();
        vector<vector<int>> dp(n , vector<int>(target+1 , -1));

        return solve(n-1 ,  target , nums, dp);
        
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 3};
    int target = 6;
    Solution obj;
    cout << obj.countSubsets(nums, target) << endl;
    return 0;
}