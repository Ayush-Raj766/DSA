#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(int i, int target, vector<int>& arr, vector<vector<int>>& dp) {
        if (target == 0)
            return dp[i][target] = true;

        if (i == 0)
            return dp[i][target] = (arr[0] == target);

        if (dp[i][target] != -1)
            return dp[i][target];

        bool notTake = solve(i - 1, target, arr, dp);

        bool take = false;
        if (arr[i] <= target)
            take = solve(i - 1, target - arr[i], arr, dp);

        return dp[i][target] = (take || notTake);
    }

    int minimumDifference(vector<int>& nums) {
        int n = nums.size();

        if (n == 0)
            return 0;

        int sum = 0;
        for (int x : nums)
            sum += x;

        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

        for (int target = 0; target <= sum; target++) {
            solve(n - 1, target, nums, dp);
        }

        int mini = INT_MAX;

        for (int s1 = 0; s1 <= sum / 2; s1++) {
            if (dp[n - 1][s1] == 1) {
                int s2 = sum - s1;
                mini = min(mini, abs(s2 - s1));
            }
        }

        return mini;
    }
};
int main()
{
    vector<int> arr = {1, 2, 3, 4};

    Solution sol;
    cout << "The minimum absolute difference is: " << sol.minimumDifference(arr) << endl;
    return 0;
}