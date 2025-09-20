#include<bits/stdc++.h>
using namespace std;

bool searchNext(vector<vector<char>>& board, string &word, int row, int col, int index) {
    if (index == word.size()) return true; // All characters matched

    // Check boundaries and character match
    if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[index]) {
        return false;
    }

    char temp = board[row][col];
    board[row][col] = '#'; // Mark as visited

    // Explore all 4 directions
    bool found = searchNext(board, word, row + 1, col, index + 1) ||
                 searchNext(board, word, row - 1, col, index + 1) ||
                 searchNext(board, word, row, col + 1, index + 1) ||
                 searchNext(board, word, row, col - 1, index + 1);

    board[row][col] = temp; // Backtrack
    return found;
}

bool exist(vector<vector<char>>& board, string word) {
    int rows = board.size();
    int cols = board[0].size();

    int index = 0;

    if(board[0][0] == word[index]){
        if(searchNext(board, word, 0, 0, index)){
            return true;
        }
    }
    return false;
}

int main() {
      vector<vector<char>> board {{'A','B','C','E'},
                                    {'S','F','C','S'},
                                    {'A','D','E','E'}};

        string word = "ABCCED";

        bool res = exist(board, word);
        if(res==1)
        cout<<"True"<<endl;
        else
        cout<<"False"<<endl;
    return 0;
}