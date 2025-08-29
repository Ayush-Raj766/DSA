#include <bits/stdc++.h>
using namespace std;

int onecount(vector<int> &row, int m)
{
    int l = 0;
    int r = m - 1;
    int count = 0;
    while (r >= l)
    {
        int mid = (l + r) / 2;

        if (row[mid] == 1)
        {
            count = m - mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return count;
}

int main()
{
    int n, m;
    cout << "enter number of row";
    cin >> n;
    cout << "enter number of columns";
    cin >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    cout << "enter elements of matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    int maxCount = 0;
    int maxRow = -1;
    for (int i = 0; i < n; i++)
    {
        int res = onecount(matrix[i], m);
        if (maxCount < res)
        {
            maxCount = res;
            maxRow = i;
        }
    }

    cout << "Row with maximum 1s: " << maxRow << endl;
    return 0;
}