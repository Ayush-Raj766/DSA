#include <bits/stdc++.h>
using namespace std;

int index(int arr[] ,  int n ){
    if(n ==0 ){
        return arr[0];
    }
    if(arr[0]!=arr[1]){
        return arr[0];
    }
    if(arr[n-1]!=arr[n-2]){
        return arr[n-1];
    }

    int l =1;
    int r =n-2;
    while(r>=l){
        int mid = (l+r)/2;
        if(arr[mid] != arr[mid+1] && arr[mid] != arr[mid-1]){
            return arr[mid];
        }
        if(mid%2==1 && (arr[mid] ==arr[mid-1])){
                l =mid+1;

        }
        else {
            r = mid-1;
        }
    }
    return -1;
}

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
    

    cout << "rotating time is = " << index(arr, n);
    return 0;
}