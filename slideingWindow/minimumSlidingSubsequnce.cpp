#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string minWindow(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        int start = -1, minlen = INT_MAX;
        int i = 0;
    
        while (i < n)
        {
            int j = 0;
            while( i < n)
            {
                if (s[i] == t[j])
                {
                    j++;
                }
                if (j == m)
                break;
                i++;
            }
            
            if (i == n)
                break;

            int end = i;
            j = m - 1;
            for (i = end; i >= 0; i--)
            {
                if (s[i] == t[j])
                {
                    j--;
                }
                if (j < 0)
                    break;
            }
            int startIndex = i;
            int len = end - startIndex + 1;
            if (len < minlen)
            {
                minlen = len;
                start = startIndex;
            }
            i = startIndex +1;
        }
        if (start == -1)
            return "";
        return s.substr(start, minlen);
    }
};

int main()
{
    Solution sol;
    string s1 = "cabwefgewcwaefgcf";
    string s2 = "cae";
    cout << sol.minWindow(s1, s2) << endl;
    return 0;
}