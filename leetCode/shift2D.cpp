#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n =grid.size();
        int m  = grid[0].size();

        int s = m*n;
        k %= s;

        vector<int> oneD(s);
        int p = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                oneD[p++] = grid[i][j];
            }
        }

        for (int i = 0; i < s; i++) {
            grid[i / m][i % m] = oneD[(s + i - k) % s];
        }

        return grid;


        
    }
};

int main() {

    Solution sol;
    vector<vector<int>> grid = {{1,2,3},{4,5,6},{7,8,9}};
    int k = 4;
    sol.shiftGrid(grid, k);
    for(int i = 0 ; i < grid.size() ; i++){
        for(int j = 0 ; j < grid[0].size() ; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}