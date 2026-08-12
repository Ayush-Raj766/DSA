#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
    {
        if (day == 0)
        {
            int maxi = 0;
            for (int i = 0; i < 3; i++)
            {
                if (i != last)
                {
                    maxi = max(maxi, points[0][i]);
                }
            }
            return maxi;
        }

          if (dp[day][last] != -1)
            {
                return dp[day][last];
            }

        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                int point = points[day][i] + solve(day - 1, i, points, dp);
                maxi = max(maxi, point);
            }
        }
        return dp[day][last] = maxi;
    }

    int ninjaTraining(int n, vector<vector<int>> &points)
    {
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return solve(n - 1, 3, points, dp);
    }
};

int main()
{
    vector<vector<int>> points = {{10, 40, 70},
                                  {20, 50, 80},
                                  {30, 60, 90}};

    int n = points.size(); // Get the number of days
    // Call the ninjaTraining function to find the maximum points and print the result
    Solution obj;   
    cout << obj.ninjaTraining(n, points);
    return 0;
}