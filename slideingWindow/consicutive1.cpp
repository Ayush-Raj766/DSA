#include<bits/stdc++.h>
using namespace std;

int longestOnes(vector <int> &num , int k){
    int l=0;
    int r=0;
    int limit =0;
    int count =0;
    int n = num.size();
    while(r<n){
        if(num[r] == 0){
            limit++;
        }
        while(limit> k){
            if(num[l]==0){
                limit--;
            }
            l++;
        }
        count = max(count , r-l+1);
        r++;

    }
    return count;
}

int main() {
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 3;
    cout << longestOnes(nums, k) << endl; // Output: 10
    return 0;
}