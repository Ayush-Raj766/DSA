#include<bits/stdc++.h>
using namespace std;

int repeatedNTimes(vector<int>& nums){
    sort(nums.begin() , nums.end());
    int n= nums.size();
    for(int i = 1 ; i<n ; i++){
        if(nums[i] == nums[i-1]){
           if(nums[i] == nums[i-1])
        return nums[i];
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {5,1,5,2,5,3,5,4};
    cout<<repeatedNTimes(nums)<<endl;

    return 0;
}