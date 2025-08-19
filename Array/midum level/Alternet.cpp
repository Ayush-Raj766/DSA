#include<bits/stdc++.h>
using namespace std;

int main() {
    int n ;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans[n];
    int pos=0 , neg = 1;

    for(int i =0;i<n;i++){
        if(arr[i]>0){
            ans[pos] = arr[i];
            // cout<<"pos ="<<pos<<"arr="<<ans[pos];
            pos = pos + 2;
            
        }
        else{
            ans[neg] = arr[i];

            neg = neg + 2;
        }
    }
    
    cout << "Rearranged array: ";
    for(int i = 0; i<n ;i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}