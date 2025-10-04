#include<bits/stdc++.h>
using namespace std;

int NiceSubarray(vector <int> &nums , int k){
    int l=0;
    int count =0;
    int sum =0;
    int n = nums.size();

     for (int r = 0; r < n; r++) {
        if(nums[r]%2 ==0) nums[r] =0;
        else nums[r] =1;
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
    vector<int> nums = {1, 5 ,2,1,1};
    int k = 3;
    cout << NiceSubarray(nums, k) << endl; // Output: 10
    return 0;
}