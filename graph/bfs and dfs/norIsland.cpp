#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis, int n, int m){
        vis[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0 ; i < 4 ; i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == '1'){
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n , vector<int>(m,0));
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(vis[i][j] == 0 && grid[i][j] == '1'){
                    count++;
                    bfs(i,j,grid,vis,n,m);
                }
            }
        }
        return count;
    }
};

int main() {
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    // Create Solution object
    Solution obj;
    // Call function and print result
    cout << obj.numIslands(grid) << endl;
    return 0;
}