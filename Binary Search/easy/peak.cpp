#include<bits/stdc++.h>
using namespace std;

int index(int arr[] , int n){
    if(n ==0 ){
        return 0;
    }
    
    int l = 0 ;
    int r = n-1;
    while(r>=l){
        int mid = (l+r)/2;
        if(arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1]){
            return mid;
        }
        if(arr[l]<arr[mid]){
            l = mid+1;
        }
        else if(arr[mid] <arr[r]){
            r = mid-1;
        }
        
    }
}

int main() {
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