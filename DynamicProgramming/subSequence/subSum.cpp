#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    bool solve(int i , int target , vector<int> &arr , vector<vector<int>> &dp){
        if(target == 0) return true;
        if(i == 0) return arr[0] == target;

        if(dp[i][target] != -1 ) return dp[i][target];

        bool notTake = solve(i-1 , target , arr , dp);
        bool take = false;
        if(arr[i] <= target) take = solve(i-1 , target - arr[i] , arr , dp);

        return dp[i][target] = take || notTake;
    }

    bool subsetSumToK(int n , int k , vector<int> &arr){
         vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return solve(n - 1, k, arr, dp);
    }

};

int main() {
    vector<int> arr = {1, 2, 3, 4};
    int k = 4;
    int n = arr.size();

    Solution sol;
    if (sol.subsetSumToK(n, k, arr))
        cout << "Subset with the given target found";
    else
        cout << "Subset with the given target not found";
    return 0;
}