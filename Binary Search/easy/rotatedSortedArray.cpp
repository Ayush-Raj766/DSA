#include<bits/stdc++.h>
using namespace std;

int index(int arr[] , int n , int key){
    int l =0;
    int r =n-1;
    int ans = -1;
    while(r>=l){
        int mid = (l+r)/2;
        if(arr[mid] == key){
            
            return mid;
        }

        
        if(arr[mid]<=arr[r]){
            if((arr[mid]<=key) &&  (arr[r] >=key)){
                l=mid+1;
            }
            else{
                r = mid-1;
            }
            
        }

        else if (arr[mid]>=arr[l]){
            if((arr[mid]>=key) &&  (arr[l] <=key)){
                r=mid-1;
            }
            else{
                l = mid+1;
            }
        }
    }
    return -1;
    
    
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
    cout<<"enter key = ";
    cin>>key;

    cout<<"index is = "<<index(arr , n , key);
    return 0;
}
