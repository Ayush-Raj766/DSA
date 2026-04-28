#include<bits/stdc++.h>
using namespace std;

int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({nums[i], nums[i]*k});
    }
        int ans = n;
        for (int i = 0; i < n; i++) {
            int ind = n ;
            for (int j = i; j < n; j++) {
                if (v[j].first > v[i].second) {
                    ind = j;
                    break;
                }
            }
           int kept = ind - i;
        int removed = n - kept;

        ans = min(ans, removed);
    }

    return ans;
}

int main() {
    vector<int> nums = {1, 5, 9, 3, 7, 12, 25, 54};
    int k = 3;
    cout << minRemoval(nums , k) << endl;
    return 0;
}