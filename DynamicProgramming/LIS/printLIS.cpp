#include<bits/stdc++.h>
using namespace std;

class Solution{
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

    vector<int> longestIncreasingSubsequence(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n+1, vector<int>(n, -1));

        solve(-1, 0, nums, dp);

        vector<int> lis;

        int prev = -1;
        int curr = 0;
        while (curr < n) {
            int notTake = solve(prev, curr + 1, nums, dp);

            int take = -1;
            if (prev == -1 || nums[curr] > nums[prev]) {
                take = 1 + solve(curr, curr + 1, nums, dp);
            }

            if (take >=notTake) {
                lis.push_back(nums[curr]);
                prev = curr;
            }
            curr++;

        }

        return lis;
    }
};

int main() {
     vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    Solution sol;
    vector<int> lis = sol.longestIncreasingSubsequence(nums);

    cout << "LIS: ";
    for (int x : lis) cout << x << " ";
    cout << endl;
}