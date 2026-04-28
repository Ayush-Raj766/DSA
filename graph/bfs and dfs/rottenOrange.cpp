#include<bits/stdc++.h>
using namespace std;
int orangesRotting(vector<vector<int>>& grid){
    if(grid.empty()) return 0;
    int rows = grid.size();
    int cols = grid[0].size();
    queue<pair<pair<int,int>, int>> q;
   vector<vector<int>> vis(rows, vector<int>(cols, 0));

    for(int i = 0 ; i<rows ; i++){
        for(int j = 0 ; j<cols ; j++){
            if(grid[i][j] == 2){
                q.push({{i,j},0});
                vis[i][j] = 2;
            }
        }

    }
    int time = 0;
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        q.pop();
        time = max(time, t);
        for(int i = 0 ; i < 4 ; i++){
            int nrow = r + dr[i];
            int ncol = c + dc[i];
            if(nrow >= 0 && nrow < rows && ncol >= 0 && ncol <cols && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1){
                vis[nrow][ncol] = 2;
                q.push({{nrow, ncol}, t + 1});
            }
        }

    }
    for(int i = 0 ; i<rows ; i++){
        for(int j = 0 ; j<cols ; j++){
            if(grid[i][j] == 1 && vis[i][j] != 2){
                return -1;
            }
        }
    }
    return time;
    
}

int main() {
     vector<vector<int>> v{{2, 1, 1}, 
                          {1, 1, 0}, 
                          {0, 1, 1}};
    
    // Call the function to calculate minimum time required
    int rotting = orangesRotting(v);

    // Output the result
    cout << "Minimum Number of Minutes Required " << rotting << endl;
    return 0;
}