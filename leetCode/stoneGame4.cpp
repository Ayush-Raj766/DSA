#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool perfectSquare(int n) {
        int root = sqrt(n);
        return root * root == n;
    }
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                if (!dp[i - j * j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};

int main() {
    int n = 7;
    Solution sol;
    cout << sol.winnerSquareGame(n) << endl;
    
    return 0;
}