#include<bits/stdc++.h>
using namespace std;

int specialTriplets(vector<int> & nums ){
    int n = nums.size();
    unordered_map<int , int> mp1 , mp2;
    for(auto nums : nums){
        mp1[nums]++;
    };
    
    int ans =0;

    for(int j = 0 ; j < n ; j++){
        int mid = nums[j];
        mp1[mid]--;
         int target = mid * 2;

         int leftcount = mp2[target];
         int rightcount = mp1[target];

         ans = (ans + (leftcount * rightcount));
         mp2[mid]++;
    }
    return ans;
}

int main() {
    vector<int> nums={8,4,2,8,4};
    
    cout<<specialTriplets(nums)<<endl;
    return 0;
}