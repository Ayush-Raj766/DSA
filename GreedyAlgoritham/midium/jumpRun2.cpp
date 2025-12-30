#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    // int jump(vector<int>& nums , int idx , int j){
    //     int n = nums.size();
    //     if(idx >= n-1){
    //         return j;
    //     }
    //     int mini =INT_MAX;
    //     for(int i = 1 ; i <= nums[idx] ; i++){
    //         mini = min(mini ,  jump(nums , idx+i , j+1));
    //     }
    //     return mini;
    // }

    int jump (vector<int>& nums){
        int jump =0 ;
        int l = 0 ;
        int r= 0;
        int n =  nums.size();
        while(r<n-1){
            int far = 0 ;

            for(int i = l ; i<=r ; i++){
                far= max(far, i + nums[i]);
            }
            l = r+1; 
            r = far;
            jump++;
        }
        return jump;
    }

};

int main() {
    Solution sol;
    vector<int> nums = {2, 3, 1, 1, 4};

    cout << "Minimum jumps required: " << sol.jump(nums) << endl;

    return 0;
}