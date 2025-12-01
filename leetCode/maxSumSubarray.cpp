#include<bits/stdc++.h>
using namespace std;


int maxsum(vector<int>& nums, int WindowSize) {
    int n = nums.size();
    long long maxSum = LONG_LONG_MIN;
    int l=0;
    long long currentSum =0;
    for(int r =0 ; r<n ; r++){
        currentSum += nums[r];
        while((r - l + 1) > WindowSize){
            currentSum -= nums[l];
            l++;
        }
        if((r - l + 1) == WindowSize){
            maxSum = max(maxSum, currentSum);
        }
    }
    return maxSum;
}

long long maxSubarraySum(vector<int>& nums, int k) {
    // int n = nums.size();
    // long long maxSum = LONG_LONG_MIN;
    // for(int i = 0 ; i<n ;i++){
    //     long long currentSum =0;
    //     for(int j = i ; j<n ; j++){
    //         currentSum += nums[j];
    //         if((j - i + 1) % k == 0){
    //         maxSum = max(maxSum, currentSum);
    //         }
    //     }
    // }
    // return maxSum;
    long long maxSum = LONG_LONG_MIN;
    for(int i = k ; i<= nums.size() ; i+=k){
    
        long long ans = maxsum(nums , i);
        // cout<<ans<<" ";
        if(i == k) {
            maxSum = ans;
        } else {
            maxSum = max(maxSum , ans);
        }
    }
    return maxSum;
}

int main() {
    vector <int> nums ={1,2} ;
    int k = 1;
    //  maxSubarraySum( nums,  k);
    cout<<maxSubarraySum( nums,  k);
    return 0;
}