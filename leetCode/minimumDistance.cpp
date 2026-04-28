#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        int ans = INT32_MAX;
        for (auto &it : mp) {
            vector<int> &v = it.second;
            if(v.size() < 3)   continue;
            for (int i = 0; i < v.size() - 2; i++) {
                ans = min(ans, 2*(v[i + 2] - v[i]));
            }
        }
        if(ans == INT32_MAX)    return -1;
        
        return ans;
    }
};

int main() {
    vector<int> nums = {1,2,1,1,3};
    Solution sol;
    cout << sol.minimumDistance(nums) << endl;
    return 0;
}