#include <bits/stdc++.h>
using namespace std;

int minCost(vector<vector<int>> &grid, int k)
{
    int n = grid.size();
    int m = grid[0].size();
    int last = grid[n - 1][m - 1];
    int i = 0;
    int j = 0;
    int totalcost = 0;
    int attempt = 0;
    while (i != n - 1 && j != m - 1)
    {
        if (grid[i][j] >= last && attempt <= k)
        {
            k++;
            return totalcost;
        }
        else
        {

            if (grid[i + 1][j] > grid[i][j + 1])
            {
                totalcost += grid[i][j + 1];
                j = j + 1;
            }
            else if (grid[i + 1][j] < grid[i][j + 1])
            {
                totalcost += grid[i + 1][j];
                i = i + 1;
            }
        }
    }
    return totalcost;
}

int main()
{
    vector<vector<int>> grid = {{1, 3, 3}, {2, 5, 4}, {4, 3, 5}};
    int k = 2;

    cout<<minCost(grid, k)<<endl;

    return 0;
}