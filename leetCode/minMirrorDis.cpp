#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverseNum(int num) {
        int rev = 0;
        while (num > 0) {
            rev = rev * 10 + num % 10;
            num /= 10;
        }
        return rev;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int dis = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            int rev = reverseNum(nums[i]);
            for (int j = i + 1; j < nums.size(); j++) {
                if (rev == nums[j]) {
                    dis = min(dis, j - i);
                }
            }
        }
        return dis == INT_MAX ? -1 : dis;
        
    }
};

int main() {
    vector<int> nums = {12,21,45,33,54};
    Solution sol;
    cout << sol.minMirrorPairDistance(nums) << endl;

    return 0;
}