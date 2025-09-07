// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     string s;
//     cout << "enter the string: ";
//     cin >> s;
//     int total_beauty = 0;
//     for (int i = 0; i < s.length(); i++)
//     {
//         for (int j = i; j < s.length(); j++)
//         {
//             string temp = s.substr(i, j - i + 1);
//             map<char, int> m;
//             for (int x : temp)
//             {
//                 m[x]++;
//             }
//             int max_freq = INT_MIN;
//             int min_freq = INT_MAX;

//             for (auto it : m)
//             {
//                 max_freq = max(max_freq, it.second);
//                 min_freq = min(min_freq, it.second);
//             }

//             int beauty = max_freq - min_freq;
//             total_beauty += beauty;
//         }
//     }

//     cout << "Total beauty: " << total_beauty << endl;
//     return 0;
// }












#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cout << "enter the string: ";
    cin >> s;
    int total_beauty = 0;
    for (int i = 0; i < s.length(); i++)
    {
        int ind[26] = {0};
        for (int j = i; j < s.length(); j++)
        {
            ind[s[j] - 'a']++;
            int max_freq = INT_MIN;
            int min_freq = INT_MAX;
            for (int k = 0; k < 26; k++)
            {
                if (ind[k] > 0)
                {
                    max_freq = max(max_freq, ind[k]);
                    min_freq = min(min_freq, ind[k]);
                }
            }
            int beauty = max_freq - min_freq;
            total_beauty += beauty;
        }
    }

    cout << "Total beauty: " << total_beauty << endl;
    return 0;
}