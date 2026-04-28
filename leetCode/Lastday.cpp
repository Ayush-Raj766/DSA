#include <bits/stdc++.h>
using namespace std;

bool canCross(int row , int col , vector<vector<int>>& cells , int mid){
    if(cells.empty()) return false;
    vector<vector<int>> grid(row , vector<int>(col , 0));
    for(int i = 0 ; i < mid ; i++){
        int r = cells[i][0] - 1;
        int c = cells[i][1] - 1;
        grid[r][c] = 1; // mark as water
    }

    queue<pair<int,int>> q;
    vector<vector<int>> vis(row , vector<int>(col , 0));

    for(int j = 0 ; j < col ;  j++){
        if(grid[0][j] == 0 ){
            q.push({0,j});
            vis[0][j] = 1;
        }
    }
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    while(!q.empty()){
        int r = q.front().first;;
        int c = q.front().second;
        q.pop();
        if(r == row - 1){
            return true;
        }

        for(int i = 0 ; i < 4 ; i++){
            int nrow = r + dr[i];
            int ncol = c + dc[i];
            if(nrow >= 0 && nrow < row && ncol >= 0 && ncol < col && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 0){
                vis[nrow][ncol] = 1;
                q.push({nrow, ncol});
            }
        }
    
    }
    return false;
}

int latestDayToCross(int row ,int col , vector<vector<int>>& cells){
    int l = 0;
    int r = row * col;
    int ans = 0;

    while(l<=r){
        int mid = l + (r - l) / 2;
        if(canCross(row , col , cells , mid)){
            ans = mid;
            l = mid + 1;
        }
        else{
            r = mid -1;
        }
    }
    return ans;
}

int main()
{
    int row = 3;
    int col = 3;
    vector<vector<int>> cells = {{1, 1},{ 2, 1 },{ 3, 1 },{ 2, 2 },{ 1, 2 },{ 3, 2 },{ 2, 3 },{ 1, 3 },{ 3, 3 }};
    cout<<latestDayToCross(row, col, cells)<<endl;

    return 0;
}