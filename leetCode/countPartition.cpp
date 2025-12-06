#include<bits/stdc++.h>
using namespace std;
int countPartition(vector<int>&nums , int k){
    int count = 1;
    int n = nums.size();
    int max = nums[0];
    int min = nums[0];
    for(int i=1;i<n;i++){
        if(nums[i]>=max){
            max = nums[i];
        }
        if(nums[i]<min){
            min = nums[i];
        }
        if((max - min) > k){
            count++;
            max = nums[i];
            min = nums[i];
        }
    }
    return count;
}

int main() {
    vector<int> nums={9,4,1,3,7};
    int k =4;
    cout << countPartition(nums , k)<<endl;
    return 0;
}