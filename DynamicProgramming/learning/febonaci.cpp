#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int fib(int n, vector<int> &dp)
    {
        if (n <= 1)
            return n;

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    }
};

int main()
{
    int n;
    cout << "enter the number =";
    cin >> n;

    vector<int> dp(n + 1, -1);

    Solution obj;

    cout << obj.fib(n, dp) << endl;

    return 0;
}