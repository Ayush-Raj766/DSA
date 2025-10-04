#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countarray(vector<int>& nums, int k) {
        int n = nums.size();
        int l=0;
        int ans=0;
        int count =0;   
        unordered_map<int,int> map;
        for(int r =0;r<n;r++){

            map[nums[r]]++;
            while(map.size()>k){
                map[nums[l]]--;
                if(map[nums[l]]==0){
                    map.erase(nums[l]);
                }
                l++;
            }
            count = count + (r - l + 1);
        
        }
        return count;

    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return countarray(nums,k) - countarray(nums,k-1);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 1, 2, 3};
    int k = 2;
    cout << sol.subarraysWithKDistinct(nums, k) << endl;
    return 0;
}