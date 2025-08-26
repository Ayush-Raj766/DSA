#include<bits/stdc++.h>
using namespace std;

int index(int arr[] ,  int n ){
    int l = 0 ;
    int r =n-1;
    int ans = INT_MAX;
    while(r>=l){
        int mid = (l+r)/2;
        if(arr[mid]>=arr[l]){
            if(arr[l]>=arr[r]){
                l = mid+1;
                
            }
            else{
                r =mid-1;
            }
            ans = min(ans, arr[mid]);
            
        }
        else if(arr[mid]<=arr[r]){
            if(arr[l] <=arr[r]){
                r=mid-1;
            }
            else{
                l =mid+1;
            }
            ans = min(ans, arr[mid]);
            
        }
    }
    return ans;
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
    int key;

    cout<<"index is = "<<index(arr , n );
    return 0;
}