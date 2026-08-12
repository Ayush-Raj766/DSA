#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int layers = min(m, n) / 2;

        for(int l = 0 ; l <layers;l++){

            for(int i = 0 ; i < k ; i++){
                int temp = grid[l][l];
                for(int j = l ; j < n-l-1 ; j++){
                    grid[l][j] = grid[l][j+1];
                }
                for(int j = l ; j < m-l-1 ; j++){
                    grid[j][n-l-1] = grid[j+1][n-l-1];
                }
                for(int j = n-l-1 ; j > l ; j--){
                    grid[m-l-1][j] = grid[m-l-1][j-1];
                }
                for(int j = m-l-1 ; j > l+1 ; j--){
                    grid[j][l] = grid[j-1][l];
                }
                grid[l+1][l] = temp;
            }
        }
        return grid;

    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {{1,2,3,8,85,7},{4,5,6,9,78,8},{7,8,9,10,55,6}};
    int k = 1;
     for (const auto& row : grid) {
        for (const auto& cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    cout << "After rotation:" << endl;
    vector<vector<int>> result = sol.rotateGrid(grid, k);
    for (const auto& row : result) {
        for (const auto& cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    return 0;
}