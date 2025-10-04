#include<bits/stdc++.h>
using namespace std;

int SubarraySum(vector <int> &nums , int k){
    int l=0;
    int count =0;
    int sum =0;
    int n = nums.size();

     for (int r = 0; r < n; r++) {
        sum += nums[r];
        while (sum > k) {
            sum -= nums[l];
            l++;
        }

        if (sum == k) {
            int temp = l;
            while (temp <= r) {
                count++;
                if (k > 0 && nums[temp] == 1) break;
                temp++;
            }
        }
    }
    return count;
    
}

int main() {
    vector<int> nums = {0,0,0,0,0,0,1,0,0,0};
    int k = 0;
    cout << SubarraySum(nums, k) << endl; // Output: 10
    return 0;
}