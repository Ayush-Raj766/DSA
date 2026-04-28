#include<bits/stdc++.h>
using namespace std;

long long maxSumTrionic(vector<int>& nums) {
    int n = nums.size();
    if(n < 4 ) return 0;
    vector<long long> incL(n) , incR(n) , dec(n);
    
    incL[0] = nums[0];
    for(int i=1;i<n;i++){
        if(nums[i] > nums[i-1]){
            incL[i] = incL[i-1] + nums[i];
        } else {
            incL[i] = nums[i];
        }
    }

    incR[n-1] = nums[n-1];
    for(int i=n-2;i>=0;i--){
        if(nums[i] < nums[i+1]){
            incR[i] = incR[i+1] + nums[i];
        } else {
            incR[i] = nums[i];
        }
    }

    dec[0] = nums[0];
    for(int i=1;i<n;i++){
        if(nums[i] < nums[i-1]){
            dec[i] = dec[i-1] + nums[i];
        } else {
            dec[i] = nums[i];
        }
    }

    long long ans = 0;
    for(int i=1;i<n-1;i++){
       if (incL[i - 1] > nums[i - 1] &&
            dec[i] > nums[i] &&
            incR[i + 1] > nums[i + 1]) {

            ans = max(ans, incL[i - 1] + dec[i] + incR[i + 1]);
        }

    }
    return ans;

}

int main() {
    vector<int> nums= {2, 4, 7, 5, 3, 6, 8};
    cout<<maxSumTrionic(nums);
    return 0;
}