#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> solveLIS(vector<int> &arr)
    {
        int n = arr.size();

        vector<int> dp1(n, 1);
        int lis = 1;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (arr[i] > arr[j] && dp1[i] < 1 + dp1[j])
                {
                    dp1[i] = max(dp1[i], 1 + dp1[j]);
                }
            }
            if (dp1[i] > lis)
            {
                lis = dp1[i];
            }
        }

        return dp1;
    }

    vector<int> solveLDS(vector<int> &arr)
    {
        int n = arr.size();

        vector<int> dp2(n, 1);
        int lds = 1;

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] > arr[j] && dp2[i] < 1 + dp2[j])
                {
                    dp2[i] = 1 + dp2[j];
                }
            }
        
        if (dp2[i] > lds)
        {
            lds = dp2[i];
        }
    }

    return dp2;
}

int
LongestBitonicSequence(vector<int> &arr)
{

    int n = arr.size();

    vector<int> lis = solveLIS(arr);
    vector<int> lds = solveLDS(arr);

    int maxLength = 0;
    for (int i = 0; i < n; i++)
    {
        maxLength = max(maxLength, lis[i] + lds[i] - 1);
    }

    return maxLength;
}
}
;

int main()
{
    vector<int> arr = {10, 20, 30, 40, 50, 40, 30, 20};

    // Creating an object of Solution class
    Solution sol;

    // Function call to get the length of longest bitonic sequence
    int lengthOfLongestBitonicSequence = sol.LongestBitonicSequence(arr);

    //  Output
    cout << "The length of the Longest Bitonic Sequence is: " << lengthOfLongestBitonicSequence << endl;
    return 0;
}