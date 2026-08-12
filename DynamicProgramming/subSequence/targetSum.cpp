#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(int i, int target , vector<int>&arr , vector<vector<int>>&dp){

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(n , vector<int>(target+1000 , -1));
        return solve(n-1 , target + 1000 , nums , dp);
    }
};
int main() {
    Solution sol;
    vector<int> nums = {1,1,1,1,1};
    int target = 3;
    cout << sol.findTargetSumWays(nums, target) << endl; // Output: 5
    return 0;
    return 0;
}