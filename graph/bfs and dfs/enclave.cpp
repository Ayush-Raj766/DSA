#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

     void bfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, int n, int m){
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
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    int numberOfEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n , vector<int>(m,0));

        for(int i = 0 ; i < n ; i++){
            if(vis[i][0] == 0 && grid[i][0] == 1){
                bfs(i,0,grid,vis,n,m);
            }
            if(vis[i][m-1] == 0 && grid[i][m-1] == 1){
                bfs(i,m-1,grid,vis,n,m);
            }
        }

        for(int j = 0 ; j < m ; j++){
            if(vis[0][j] == 0 && grid[0][j] == 1){
                bfs(0,j,grid,vis,n,m);
            }
            if(vis[n-1][j] == 0 && grid[n-1][j] == 1){
                bfs(n-1,j,grid,vis,n,m);
            }
        }
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(vis[i][j] == 0 && grid[i][j] == 1){
                    count++;    
                }
            }
        }
        return count;
    }
};

int main() {
     vector<vector<int>> grid{
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };

    // Create Solution instance
    Solution obj;

    // Compute and print the number of enclaves
    cout << obj.numberOfEnclaves(grid) << endl; // Expected: 3
    return 0;
}