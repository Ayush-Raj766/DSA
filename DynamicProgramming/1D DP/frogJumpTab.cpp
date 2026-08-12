#include<bits/stdc++.h>
using namespace std;

class Solution{
    public: 
    int frogJump(vector<int> &height){
        int n = height.size();

        vector<int> dp( n , -1);

        dp[0] = 0;
        for(int i = 1 ; i < n ; i++){
            int jumpOne =  abs(height[i] - height[i-1] ) + dp[i-1];
            int jumpTwo = INT_MAX;
            if(i > 1){
                jumpTwo = abs(height[i] - height[i-2]) + dp[i-2];
            }
            dp[i] = min(jumpOne, jumpTwo);
        }
        return dp[n-1];
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