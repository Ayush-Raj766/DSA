#include <bits/stdc++.h>
using namespace std;
string removeKdigits(string num, int k)
{
    stack<char> st;
    int j = k;
    for (int i = 0; i < num.length(); i++)
    {

        char ch = num[i];
        while (!st.empty() && st.top() > ch && j > 0)
        {
            st.pop();
            j--;
        }
        st.push(num[i]);
    }
    // while (j > 0 && !st.empty())
    //     {
    //         st.pop();
    //         j--;
    //     }
    string result = "";
    while (!st.empty())
    {
        result.push_back(st.top());
        st.pop();
    }
    reverse(result.begin(), result.end());
    int idx = 0;
    while (idx < result.size() && result[idx] == '0')
        idx++;
    result = result.substr(idx);

    if (result.empty())
    {
        return "0";
    }
    else
    {
        return result;
    }
}
int main()
{
    string num;
    int k;
    cout << "Enter number string: ";
    cin >> num;
    cout << "Enter k: ";
    cin >> k;

    cout << "Smallest number after removing " << k << " digits: "
         << removeKdigits(num, k) << endl;
    return 0;
}