#include<bits/stdc++.h>
using namespace std;

int koko(vector<int> &arr , int n , int h){
    int l =1;
    int r = *max_element(arr.begin() , arr.end());
    int ans =0;
    int res;
    while(r>=l){
        int mid = (l+r)/2;
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
        if(ans <= h){
            r = mid -1;
            res =mid;
        }
        else{
            l=mid+1;
            
        }
        ans = 0;
    }
    return res;
}
int main() {
     int n , h;
    cout << "enter the size = ";
    cin >> n;
    vector<int> arr(n);
    cout << "array = ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout<<"time limit is =";
    cin>> h;
    

    cout << "minimum banana is = " << koko(arr, n ,h);
    return 0;
}