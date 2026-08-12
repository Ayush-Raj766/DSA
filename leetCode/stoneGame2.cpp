#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& piles, vector<int>& prefixSum,
              vector<vector<int>>& dp, int n, int M) {

        if (n <= 0)
            return 0;

        if (dp[n][M] != -1)
            return dp[n][M];

        if (2 * M >= n)
            return dp[n][M] = prefixSum[n];

        int maxStones = 0;

        for (int x = 1; x <= 2 * M; x++) {

            int stones = prefixSum[n];

            int opponentStones =
                solve(piles, prefixSum, dp,
                      n - x, max(M, x));

            maxStones = max(maxStones,
                            stones - opponentStones);
        }

        return dp[n][M] = maxStones;
    }

    int stoneGameII(vector<int>& piles) {

        reverse(piles.begin(), piles.end());

        int n = piles.size();

        vector<int> prefixSum(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] =
                prefixSum[i] + piles[i];
        }

        vector<vector<int>> dp(
            n + 1,
            vector<int>(n + 1, -1)
        );

        return solve(piles, prefixSum, dp, n, 1);
    }
};

int main() {
    vector<int> piles = {3, 9, 1, 2 , 100};
    Solution sol;
    cout << sol.stoneGameII(piles) << endl;
    return 0;
}