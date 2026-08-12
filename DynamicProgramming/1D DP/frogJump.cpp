#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
    int solve(int ind , vector<int> &height , vector<int> &dp ){

        if(ind == 0)  return 0;

        if(dp[ind] != -1) return dp[ind];

        int jumpOne = solve (ind-1 , height ,dp) + abs(height[ind] - height[ind-1]);
        int jumpTwo = INT_MAX;
        if(ind > 1){
            jumpTwo = solve(ind-2 , height, dp) + abs(height[ind] - height[ind-2]);
        } 
        return dp[ind] = min(jumpOne,jumpTwo);
    }

    int frogJump(vector<int> &height){
        int n = height.size();
        vector<int> dp(n ,-1);

       return solve(n-1, height, dp);

    }
};

int main() {
     vector<int> height{30, 10, 60, 10, 60, 50};

    // Create Solution instance
    Solution sol;

    // Compute and print the minimum energy
    cout << sol.frogJump(height) << endl; // Expected: 40

    
    return 0;
}