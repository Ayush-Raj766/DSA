#include<bits/stdc++.h>
using namespace std;

class Solution{

    public:

    int solve(int ind , vector<int> &arr , vector<int> &dp){
        if(ind == 0) return arr[0];
        if(ind == 1) return max(arr[0] , arr[1]);
        if(dp[ind] != -1) return dp[ind];

        int pick = arr[ind] + solve(ind-2 , arr , dp);
        int notPick = 0 + solve(ind-1 , arr , dp);
        return dp[ind] = max(pick , notPick);
    }

    int maximumNonAdjacentSum(vector<int> &arr){
        int n =arr.size();

        vector<int> dp(n , -1);

        return solve(n-1 , arr , dp); ;
    }

};

int main() {
     vector<int> arr = {7,5,9,2,7};
    Solution obj;

    // Output the result
    cout << obj.maximumNonAdjacentSum(arr)<<endl;
    return 0;
}