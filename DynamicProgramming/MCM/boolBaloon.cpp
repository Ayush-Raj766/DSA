#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(int i, int j, int isTrue, string expression,
              vector<vector<vector<int>>> &dp)
    {
        if (i > j)
            return 0;
        if (i == j)
        {
            if (isTrue == 1)
                return expression[i] == 'T';
            else
                return expression[i] == 'F';
        }
        if (dp[i][j][isTrue] != -1)
        {
            return dp[i][j][isTrue];
        }
        int ways = 0;
        for (int k = i + 1; k <= j - 1; k += 2)
        {
            int lT = solve(i, k - 1, 1, expression, dp);
            int lF = solve(i, k - 1, 0, expression, dp);
            int rT = solve(k + 1, j, 1, expression, dp);
            int rF = solve(k + 1, j, 0, expression, dp);

            if (expression[k] == '&')
            {
                if (isTrue)
                {
                    ways += lT * rT;
                }
                else
                {
                    ways += lF * rF;
                    ways += lT * rF;
                    ways += lF * rT;
                }
            }
            else if (expression[k] == '|')
            {
                if (isTrue)
                {
                    ways += lT * rT;
                    ways += lT * rF;
                    ways += lF * rT;
                }
                else
                {
                    ways += lF * rF;
                }
            }
            else
            { // '^'
                if (isTrue)
                {
                    ways += lT * rF;
                    ways += lF * rT;
                }
                else
                {
                    ways += lT * rT;
                    ways += lF * rF;
                }
            }
        }
        return dp[i][j][isTrue] = ways;
    }
    int parseBoolExpr(string expression)
    {
        int n = expression.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(n, vector<int>(2, -1)));
        return solve(0, n - 1, 1, expression, dp);
    }
};

int main()
{
    Solution sol;
    string expression = "F|T^F";
    int result = sol.parseBoolExpr(expression);
    cout << "Result: " << result << endl;

    return 0;
}