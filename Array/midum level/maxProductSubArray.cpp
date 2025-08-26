#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "enter the size = ";
    cin >> n;
    int arr[n];
    cout << "array = ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int maxi = 1;
    int prod = 1;

    int i = 0;
    while (i < n)
    {
        prod *= arr[i];
        maxi = max(maxi, prod);

        // if product becomes 0, reset
        if (prod == 0) {
            prod = 1;
        }

        i++;
    }
    prod = 1;
    i = n - 1;
    while (i >= 0)
    {
        prod *= arr[i];
        maxi = max(maxi, prod);

        if (prod == 0) {
            prod = 1;
        }
        i--;
    }

    cout<<maxi;
    
    return 0;
}