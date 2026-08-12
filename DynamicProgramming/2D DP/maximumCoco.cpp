#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:

    int solve(int i , int j1 , int j2 , vector<vector<int>> &grid ,  vector<vector<vector<int>>> &dp){
        int n = grid.size();
        int m = grid[0].size();
        if(i < 0 || j1 < 0 || j2 < 0 || j1 >= n || j2 >= m) return -1e9;
        if(i == n-1){
            if(j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int maxi = -1e9;
        vector<int> dj = {-1 , 0 , 1};
        for(int d1 = 0 ; d1 < 3 ; d1++){
            for(int d2 = 0 ; d2 < 3 ; d2++){
                int value = 0;
                if(j1 == j2) value = grid[i][j1];
                else value = grid[i][j1] + grid[i][j2];
                value += solve(i+1 , j1 + dj[d1] , j2 + dj[d2] , grid , dp);
                maxi = max(maxi , value);
            }
        }
        return dp[i][j1][j2] = maxi;
    }

    int maximumChocolates(int n , int m , vector<vector<int>> &grid){
        vector<vector<vector<int>>>dp(n , vector<vector<int>>(m , vector<int>(m , -1)));

        return solve(0 , 0 , m-1 , grid , dp);
    }

};

int main() {
    vector<vector<int>> grid = {
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5}
    };
    int n = grid.size(), m = grid[0].size();
    Solution obj;
    cout << obj.maximumChocolates(n, m, grid) << endl;
    
    return 0;
}