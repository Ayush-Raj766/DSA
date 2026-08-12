#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> uniqueXors;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    int xorValue = nums[i] ^ nums[j] ^ nums[k];
                    uniqueXors.insert(xorValue);
                }
            }
        }
        return uniqueXors.size();
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2};
    int result = sol.uniqueXorTriplets(nums);
    cout << result << endl;
    return 0;
}