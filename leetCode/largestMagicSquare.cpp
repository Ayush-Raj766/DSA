#include<bits/stdc++.h>
using namespace std;

bool isMagicSquare(
    int r, int c, int k,
    vector<vector<int>>& row,
    vector<vector<int>>& col,
    vector<vector<int>>& diag1,
    vector<vector<int>>& diag2
) {
    int target = row[r][c + k] - row[r][c];


    for (int i = 0; i < k; i++) {
        if (row[r + i][c + k] - row[r + i][c] != target)
            return false;

        if (col[r + k][c + i] - col[r][c + i] != target)
            return false;
    }

    int mainDiag = diag1[r + k][c + k] - diag1[r][c];
    int antiDiag = diag2[r + k][c] - diag2[r][c + k];

    return mainDiag == target && antiDiag == target;
}

int largestMagicSquares(vector<vector<int>>& grid) {
     int rows = grid.size();
    int cols = grid[0].size();

    vector<vector<int>> row(rows, vector<int>(cols + 1, 0));
    vector<vector<int>> col(rows + 1, vector<int>(cols, 0));
    vector<vector<int>> diag1(rows + 1, vector<int>(cols + 1, 0));
    vector<vector<int>> diag2(rows + 1, vector<int>(cols + 1, 0));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            row[i][j + 1] = row[i][j] + grid[i][j];
            col[i + 1][j] = col[i][j] + grid[i][j];
            diag1[i + 1][j + 1] = diag1[i][j] + grid[i][j];
            diag2[i + 1][j] = diag2[i][j + 1] + grid[i][j];
        }
    }


    for (int k = min(rows, cols); k >= 1; k--) {
        for (int i = 0; i + k <= rows; i++) {
            for (int j = 0; j + k <= cols; j++) {
                if (isMagicSquare(i, j, k, row, col, diag1, diag2))
                    return k;
            }
        }
    }

    return 1;
}

int main() {
    vector<vector<int>> grid = {
        {4,3,8,4},{9,5,1,9},{2,7,6,2}
    };
    cout<< largestMagicSquares(grid)<<endl;
    return 0;
}