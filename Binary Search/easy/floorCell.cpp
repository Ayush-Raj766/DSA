#include<bits/stdc++.h>
using namespace std;

void index(int arr[] , int n , int key){
    int l =0;
    int r =n-1;
    pair<int ,int> ans ;
    while(r>l){
        int mid = (l+r)/2;
        if(arr[mid] >= key){
        ans.first =arr[mid-1];
            ans.second =arr[mid];
        r = mid-1;
        
        }
        else{
            l =mid+1;
        }
    }
    cout<<ans.first<<" , "<<ans.second;
    // return (ans.first,ans.second);
    
    
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

    index(arr , n , key);
    return 0;
}
