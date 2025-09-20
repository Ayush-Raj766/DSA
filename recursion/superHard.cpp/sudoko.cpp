#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<vector<char>> &board, int val)
{
    for (int i = 0; i < 9; i++)
    {
        char c = val + '0';
        if (board[i][col] == c)
            return false;
        if (board[row][i] == c)
            return false;
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
            return false;
    }

    return true;
}

bool solveSudoku(int row, int n, vector<vector<char>> &board)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == '.')
            {
                for (int x = 1; x < 10; x++)
                {
                    if (isSafe(i, j, board, x))
                    {
                        board[i][j] = x + '0';

                        if(solveSudoku(row + 1, n, board)) return true;
                        board[i][j] = '.';
                    }

                }
                return false;
            }
        }
    }
    return true;
}

int main()
{
    vector<vector<char>> board{
        {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
        {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
        {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
        {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
        {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
        {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
        {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
        {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
        {'7', '.', '6', '1', '8', '5', '4', '.', '9'}};

    solveSudoku(0, 9, board);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }
    return 0;
}