#include <bits/stdc++.h>
using namespace std;

int bestClosingTime(string customers)
{
    int n = customers.size();
    int j = 0;
    int init = INT_MAX;
    int res;
    while (j <= n)
    {
        int penalty = 0;
        for (int i = 0; i < n; i++)
        {
            if ((customers[i] == 'N' && i < j) || (customers[i] == 'Y' && i >= j))
            {
                penalty++;
            }
        }
        if (penalty < init)
        {
            init = penalty;
            res = j;
        }
        j++;
    }
    return res;
}

int main()
{
    string customers = "YYNY";
    cout << bestClosingTime(customers);
    return 0;
}