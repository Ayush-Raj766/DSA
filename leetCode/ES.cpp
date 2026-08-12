#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    const int NEG = -1e9;

    vector<int> solve(vector<string>& board,
                      vector<vector<int>>& dp,
                      vector<vector<int>>& cnt,
                      int i,
                      int j) {

        if (i < 0 || j < 0 || board[i][j] == 'X')
            return {NEG, 0};

        // Reached E
        if (i == 0 && j == 0)
            return {0, 1};

        // Memoized
        if (dp[i][j] != -1)
            return {dp[i][j], cnt[i][j]};

        auto left = solve(board, dp, cnt, i, j - 1);
        auto up = solve(board, dp, cnt, i - 1, j);
        auto diag = solve(board, dp, cnt, i - 1, j - 1);

        int best = max({left[0], up[0], diag[0]});

        // No path exists
        if (best == NEG) {
            dp[i][j] = NEG;
            cnt[i][j] = 0;
            return {NEG, 0};
        }

        long long ways = 0;

        if (left[0] == best)
            ways = (ways + left[1]) % MOD;

        if (up[0] == best)
            ways = (ways + up[1]) % MOD;

        if (diag[0] == best)
            ways = (ways + diag[1]) % MOD;

        int value = 0;
        if (board[i][j] != 'S' && board[i][j] != 'E')
            value = board[i][j] - '0';

        dp[i][j] = best + value;
        cnt[i][j] = ways;

        return {dp[i][j], cnt[i][j]};
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<vector<int>> cnt(n, vector<int>(n, 0));

        vector<int> ans = solve(board, dp, cnt, n - 1, n - 1);

        if (ans[1] == 0)
            return {0, 0};

        return ans;
    }
};

int main() {
    Solution sol;

    vector<string> board = {
        "E23",
        "2X2",
        "12S"
    };

    vector<int> ans = sol.pathsWithMaxScore(board);

    cout << "Max Score = " << ans[0] << endl;
    cout << "Ways = " << ans[1] << endl;
}