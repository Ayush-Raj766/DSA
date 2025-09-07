#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "enter the number of strings: ";
    cin >> n;
    string arr[n];
    string s;

    for (int i = 0; i < n; i++)
    {
        cout << "enter the string: ";
        cin >> s;
        arr[i] = s;
    }
    int mini =INT_MAX;
    for (int i = 0; i < n; i++)
    {
        mini = min (mini ,(int) arr[i].length());

    }
    for(int i=0 ; i<n ;i++){
        arr[i] = arr[i].substr(0, mini);
    }
    string prefix = arr[0];
    for (int i = 1; i < n; i++)
    {
        while (prefix.length() > 0 && arr[i].find(prefix) != 0)
        {
            prefix = prefix.substr(0, prefix.length() - 1);
        }
    }
    cout << "Common prefix: " << prefix << endl;
    return 0;
}