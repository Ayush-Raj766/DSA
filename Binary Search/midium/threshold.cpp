#include <bits/stdc++.h>
using namespace std;

int koko(vector<int> &arr, int n, int h)
{

    
    int l = 1;
    int r = n;
    int ans =0;
    // int count =0;
    int res;
    while (r >= l)
    {
        int mid = (l + r) / 2;
        for(int i = 0 ; i<n ;i++){
            int x;
            if(arr[i]%mid == 0){
                x = arr[i]/mid;
            }
            else{
                x = (arr[i]/mid)+1;
            }
            ans =ans +x;
        }
        if(ans> h){
            l=mid+1;
            
        }
        else{
            r=mid-1;
            res = mid;
        }
        
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
    cout << "limit =";
    cin >> h;
    cout << "minimum days is = " << koko(arr, n, h);
    return 0;
}