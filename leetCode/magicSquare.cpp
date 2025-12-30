#include<bits/stdc++.h>
using namespace std;

bool magicbox(vector<vector<int>>& grid , int row ,int cols){
    if(grid[row+1][cols+1] != 5) return false;
     bool seen[10] = {false};
     for(int i = row ; i < row + 3 ; i++){
        for(int j =cols ; j < cols+3 ; j++){
            int val = grid[i][j];
            if(val < 1 || val > 9 || seen[val]) return false;
            seen[val] = true;
        }
     }

     for(int i = 0 ; i < 3 ; i++){
        if(grid[row+i][cols] + grid[row+i][cols+1] + grid[row+i][cols+2] != 15) return false;
     }
        for(int j = 0 ; j < 3 ; j++){
            if(grid[row][cols+j] + grid[row+1][cols+j] + grid[row+2][cols+j] != 15) return false;
        }
    if(grid[row][cols] + grid[row+1][cols+1] + grid[row+2][cols+2] != 15) return false;
    if(grid[row][cols+2] + grid[row+1][cols+1] + grid[row+2][cols] != 15) return false;
    return true;
}

int numMagicSquaresInside(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int count = 0;

    for(int i = 0 ; i <= rows-3 ; i++){
        for(int j = 0 ; j <= cols-3 ; j++){
            if(magicbox(grid, i, j)){
                count++;
            }
        }
    }
    return count;
}

int main() {
    vector<vector<int>> grid = {
        {4,3,8,4},{9,5,1,9},{2,7,6,2}
    };
    cout<< numMagicSquaresInside(grid)<<endl;

    return 0;
}