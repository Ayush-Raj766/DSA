#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(vector<int> &nums, int idx, int lastSign, int flip, vector<vector<vector<int>>> &dp)
    {
        int n = nums.size();
        if (idx == n)
        {
            return 0;
        }
        if (dp[idx][lastSign][flip] != -1)
        {
            return dp[idx][lastSign][flip];
        }
        int ans = 0;

        if (lastSign == 0)
        {
                       if (nums[idx] < 0) {
                
                ans = max(ans,
                          1 + solve(nums, idx + 1, 0, flip, dp));
            }
            else if (flip == 0) {
                ans = max(ans,
                          1 + solve(nums, idx + 1, 1, 1, dp));
            }

        }
        else
        {
             if (nums[idx] > 0) {
                
                ans = max(ans,
                          1 + solve(nums, idx + 1, 1, flip, dp));
            }
            else if (flip == 0) {
                
                ans = max(ans,
                          1 + solve(nums, idx + 1, 0, 1, dp));
            }
        }
        ans = max(ans, solve(nums, idx + 1, lastSign, flip, dp));
        return dp[idx][lastSign][flip] = ans;
    }

    int maximumSubsequence(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<vector<int>>> dp1(n,
                                        vector<vector<int>>(2, vector<int>(2, -1)));

        vector<vector<vector<int>>> dp2(n,
                                        vector<vector<int>>(2, vector<int>(2, -1)));

        return max(
            solve(nums, 0, 0, 0, dp1),
            solve(nums, 0, 1, 0, dp2));
    }
};

int main()
{

    vector<int> nums = {6,
                        1,
                        -1,
                        1,
                        -1,
                        1,
                        -1};
    Solution sol;
    cout << sol.maximumSubsequence(nums) << endl;

    return 0;
}