#include <bits/stdc++.h>
using namespace std;

int koko(vector<int> &arr, int n, int h, int k)
{

    if (n < k * h)
    {
        return -1;
    }
    int l = *min_element(arr.begin(), arr.end());
    int r = *max_element(arr.begin(), arr.end());
    // int count =0;
    int res;
    while (r >= l)
    {
        int mid = (l + r) / 2;
        int bouquets = 0, flowers = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= mid)
            {
                flowers++;
                if (flowers == k)
                {
                    bouquets++;
                    flowers = 0;
                }
                
            }
            else{
                    flowers =0;
                }
        }
            if (bouquets< h )
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
                res = mid;
            }
            // count = 0;
        
    }
    return res;
}
int main()
{
    int n, h, k;
    cout << "enter the size = ";
    cin >> n;
    vector<int> arr(n);
    cout << "array = ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "nor of buke is =";
    cin >> h;
    cout << "num of flower in each buke = ";
    cin >> k;

    cout << "minimum days is = " << koko(arr, n, h, k);
    return 0;
}