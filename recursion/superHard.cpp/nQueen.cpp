#include <bits/stdc++.h>
using namespace std;


bool isSafe(int row , int col , vector<string> &board , int n){
    // Check column
    for(int i =0 ;i < row;i++){
        if(board[i][col] == 'Q') return false;
    }
    // Check upper left diagonal
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--){
        if(board[i][j] == 'Q') return false;
    }
    // Check upper right diagonal
    for(int i = row, j = col; i >= 0 && j < n; i--, j++){
        if(board[i][j] == 'Q') return false;
    }
    return true;
}

void solve(int row, int n , vector<string> &board , vector<vector<string>> &res){
    if(row == n){
        res.push_back(board);
        return;
    }
    for(int j =0 ;j < n;j++){
        if(isSafe(row , j , board , n)){
            board[row][j] = 'Q';
            solve(row + 1 , n , board , res);
            board[row][j] = '.';
        }
        
    }
   
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> board(n, string(n, '.')); // n x n chessboard
    solve(0, n, board, res);
    return res;
}

int main() {
    int n;
    cout << "Enter number of queens: ";
    cin >> n;

    vector<vector<string>> solutions = solveNQueens(n);

    cout << "Total solutions: " << solutions.size() << "\n\n";

    for (int i = 0; i < solutions.size(); i++) {
        cout << "Solution " << i + 1 << ":\n";
        for (string row : solutions[i]) {
            cout << row << "\n";
        }
        cout << "\n";
    }

    return 0;
}
