#include<bits/stdc++.h>
using namespace std;

int minOperations(vector<int>& nums , int k){
    int  n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum % k == 0) {
        return 0;
    }
        sum = sum % k;
        return sum;
}

int main() {
    vector<int> nums ={3 , 9 , 7 , 1 , 2};
    int k = 6;
    minOperations(nums, k);
    return 0;
}