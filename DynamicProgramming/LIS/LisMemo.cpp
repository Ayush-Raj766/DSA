#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int prev , int curr , vector<int>&nums , vector<vector<int>>&dp){
        if(curr ==  nums.size()){
            return 0;
        }

        if(dp[prev + 1][curr] != -1){
            return dp[prev + 1][curr];
        }
        int len = 0;
        len = 0 + solve(prev , curr + 1 , nums , dp);
        if(prev == -1 || nums[curr] > nums[prev]){
            len = max(len , 1 + solve(curr , curr + 1 , nums , dp));
        }

        return dp[prev + 1][curr] = len;
    }

    int LIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n, -1)); 

        return solve(-1 ,  0 , nums , dp);

    }
};

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    
    // Creating an object of Solution class
    Solution sol;
    int lengthOfLIS = sol.LIS(nums);
    
    cout << "The length of the LIS for the given array is: " << lengthOfLIS << endl;
    return 0;
}