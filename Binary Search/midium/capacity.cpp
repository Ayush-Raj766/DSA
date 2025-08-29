#include <bits/stdc++.h>
using namespace std;

int koko(vector<int> &arr, int n, int h, int sum)

{   
    if(n==1){
        return sum;
    }

    int l = *max_element(arr.begin(), arr.end());
    int r = sum;
    // int count =0;
    int res;
    while (r >= l)
    {
        int mid = (l + r) / 2;
        int days = 0;
        int c = 0;

        for (int i = 0; i < n; i++)
        {
            
            if (c <= mid)
            {
                c= c+arr[i];
                if (c>=mid)
                {
                    days++;
                    c = 0;
                    i=i-1;
                }
                
            }
            
        }
            if (days< h )
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
                res = mid;
            }
            // count = 0;
        
    }
    return res;
}
int main()
{
    int n, h, sum=0;
    cout << "enter the size = ";
    cin >> n;
    vector<int> arr(n);
    cout << "array = ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "nor of days =";
    cin >> h;

    for(int i =0 ; i<n ;i++){
        sum = sum + arr[i];
    }

    cout << "minimum days is = " << koko(arr, n, h, sum);
    return 0;
}