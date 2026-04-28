#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;

        for (int q : queries) {
            auto &v = mp[nums[q]];

            if (v.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            int res = INT_MAX;

            int pos = lower_bound(v.begin(), v.end(), q) - v.begin();

            int next = v[(pos + 1) % v.size()];
            int d1 = abs(next - q);
            res = min(res, min(d1, n - d1));

            int prev = v[(pos - 1 + v.size()) % v.size()];
            int d2 = abs(prev - q);
            res = min(res, min(d2, n - d2));

            ans.push_back(res);
        }

        return ans;
    }
};
int main()
{
    vector<int> nums = {1, 2, 3, 1, 2, 4, 5};
    vector<int> queries = {1, 2, 3};
    Solution sol;
    vector<int> result = sol.solveQueries(nums, queries);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}