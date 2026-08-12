#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        // Step 1: Rotate the box
        vector<vector<char>> rotatedBox(n, vector<char>(m));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rotatedBox[j][m - 1 - i] = boxGrid[i][j];
            }
        }

        // Step 2: Apply gravity
        for (int col = 0; col < m; col++) {

            int emptyRow = n - 1;

            for (int row = n - 1; row >= 0; row--) {

                if (rotatedBox[row][col] == '*') {
                    emptyRow = row - 1;
                }

                else if (rotatedBox[row][col] == '#') {

                    rotatedBox[row][col] = '.';
                    rotatedBox[emptyRow][col] = '#';

                    emptyRow--;
                }
            }
        }

        return rotatedBox;
    }
};

int main() {

    Solution sol;

    vector<vector<char>> boxGrid = {
        {'#', '.', '#', '.', '*', '#'},
        {'#', '#', '.', '.', '*', '.'},
        {'.', '#', '.', '*', '.', '#'}
    };

    vector<vector<char>> result = sol.rotateTheBox(boxGrid);

    for (auto &row : result) {
        for (auto &cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}