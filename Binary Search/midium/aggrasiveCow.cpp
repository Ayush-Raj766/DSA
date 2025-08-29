#include<bits/stdc++.h>
using namespace std;

bool cowArrange(vector<int>&arr , int dis , int h , int n){
    int cowcount = 1;
    int last =arr[0];
    for(int i =1 ; i<n ;i++){
        if(arr[i]- last >=dis){
            cowcount++;
            last = arr[i];
        }
        if(cowcount >= h){
            return true;
        }
    }
    return false;
}

int cows(vector<int> &arr , int n , int h){
    sort(arr.begin() , arr.end());
    int l =1;
    int r = arr[n-1] - arr[0];
    int res;
    while(r>=l){
        int mid = (l+r)/2;
        if(cowArrange(arr , mid , h,n) == false){
            r = mid -1;
            // res =mid+1;
        }
        else{
            l=mid+1;
            
        }
    }
    return r;
}
int main() {
     int n , h;
    cout << "enter the size = ";
    cin >> n;
    vector<int> arr(n);
    cout << "seltter co-ordinate = ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout<<"nor of cows =";
    cin>> h;
    

    cout << "maximun - minimum distancs = " << cows(arr, n ,h);
    return 0;
}