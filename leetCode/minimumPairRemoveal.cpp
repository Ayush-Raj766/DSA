#include<bits/stdc++.h>
using namespace std;

bool nondec(vector<int> nums){
    for(int i = 1 ; i < nums.size() ; i++){
        if(nums[i] < nums[i-1]){
            return false;
        }
    }
    return true;
}

int minimumPairRemoval(vector<int>& nums) {
    int count = 0;

    while(!nondec(nums)){
        int minsum = INT_MAX;
        int f = 0;

        for(int i = 0 ; i < nums.size()-1 ; i++){
            int sum = nums[i] + nums[i+1];
            if(minsum > sum){
                minsum = sum;
                f =i;
            }
        }

        nums[f] = minsum;
        nums.erase(nums.begin() + f + 1);

        count++;
    }

    return count;
   
    }

int main() {
    vector<int> nums ={7, 3, 5, 2, 6, 1, 4, 3, 8};
    cout<< minimumPairRemoval(nums)<<endl;
    return 0;
}