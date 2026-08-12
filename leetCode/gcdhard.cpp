#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& nums, int i, int j, int k, vector<vector<vector<int>>>& dp) {
        if (i == nums.size()) {
            return (j > 0 && j == k);
        }

        if (dp[i][j][k] != 0) {
            return dp[i][j][k];
        }

        int ans = solve(nums, i + 1, j, k, dp);

        ans += solve(nums, i + 1,
                     j == 0 ? nums[i] : gcd(j, nums[i]),
                     k, dp);

        ans += solve(nums, i + 1,
                     j,
                     k == 0 ? nums[i] : gcd(k, nums[i]),
                     dp);

        return dp[i][j][k] = ans;
    }
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, 0)));
        solve(nums, 0, 0, 0, dp);
        vector<int> result;
        for (long long q : queries) {
            if (q < n) {
                result.push_back(dp[0][0][q]);
            } else {
                result.push_back(0);
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4,4,2,1};
    vector<long long> queries = {5,3,1,0};
    vector<int> result = sol.gcdValues(nums, queries);
    for (int r : result) {
        cout << r << " ";
    }

    return 0;
}