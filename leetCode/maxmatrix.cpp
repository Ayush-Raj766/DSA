#include <bits/stdc++.h>
using namespace std;
long long maxMatrixSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    long long totalSum = 0;
    int minAbsValue = INT_MAX;
    int negativeCount = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int val = matrix[i][j];
            if (val < 0)
            {
                negativeCount++;
            }
            totalSum += abs(val);
            minAbsValue = min(minAbsValue, abs(val));
        }
    }
    if (negativeCount % 2 == 0)
    {
        return totalSum;
    }
    else
    {
        return totalSum - 2 * minAbsValue;
    }
}
int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {-1, -2, -3}, {1, 2, 3}};
    cout << maxMatrixSum(matrix) << endl;
    return 0;
}