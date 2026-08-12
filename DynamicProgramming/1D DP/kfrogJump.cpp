#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
    int frogJump(vector<int> &height , int k){
        int n = height.size();

        vector<int> dp( n , INT_MAX);

        dp[0] = 0;
        for(int i = 1 ; i < n ; i++){
            for(int j = 1 ; j <= k ; j++){
                if(i-j >= 0){
                    dp[i] = min(dp[i] , dp[i-j] + abs(height[i] - height[i-j]));
                }
            }
        }
        return dp[n-1];
    }
};

int main() {
     vector<int> height{15, 4, 1, 14, 15};
     int k = 3 ;
     

    // Create Solution instance
    Solution sol;

    // Compute and print the minimum energy
    cout << sol.frogJump(height , k) << endl; // Expected: 40

    
    return 0;
}