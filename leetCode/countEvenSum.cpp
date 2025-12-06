#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countPartitions(vector<int> &nums)
    {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        int prefixSum = 0;
        int count = 0;
        for (int i = 0; i < n - 1; ++i){
            prefixSum += nums[i];
            int suffixSum = totalSum - prefixSum;

            if((prefixSum - suffixSum) % 2 == 0){
                count++;
            }
        }
        return count;
    }
};

int main()
{
    vector<int> nums = {10,10,3,7,6};
    Solution sol;
    sol.countPartitions(nums);
    cout << sol.countPartitions(nums) << endl;
    return 0;
}