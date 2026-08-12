#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int gdg(int a, int b)
    {
        if (b == 0)
            return a;
        return gdg(b, a % b);
    }

    int solve(vector<int> &nums, int idx, int g1, int g2, vector<vector<vector<int>>> &dp)
    {
        int n = nums.size();
        {

            if (idx == n)
            {
                return (g1 > 0 && g1 == g2);
            }

            if (dp[idx][g1][g2] != -1)
            {
                return dp[idx][g1][g2];
            }

            int ans = solve(nums, idx + 1, g1, g2, dp);

            ans += solve(nums, idx + 1,
                         g1 == 0 ? nums[idx] : gcd(g1, nums[idx]),
                         g2, dp);

            ans += solve(nums, idx + 1,
                         g1,
                         g2 == 0 ? nums[idx] : gcd(g2, nums[idx]),
                         dp);

            return ans;
        }
    }

    int subsequencePairCount(vector<int> &nums)
    {
        int n = nums.size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));

        return solve(nums , 0, 0, 0 , dp);
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    int count = sol.subsequencePairCount(nums);
    cout << "Count of subsequence pairs: " << count << endl;
    return 0;
}