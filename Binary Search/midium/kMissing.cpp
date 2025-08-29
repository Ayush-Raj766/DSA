#include<bits/stdc++.h>
using namespace std;
 int missing(vector<int> &arr , int n , int h){
    int low = 0;
    int high =n-1;
    while (high>=low)
    {
        int mid = (low+high)/2;
        int missingNum = arr[mid] -(mid+1);
        if(missingNum <h){
            low = mid+1;

        }
        else{
            high = mid-1;
        }
    }
    return h + high +1;
    
 }
int main() {
     int n , h;
    cout << "enter the size = ";
    cin >> n;
    vector<int> arr(n);
    cout << "pages in book = ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout<<"kth palace =";
    cin>> h;
    

    cout << "maximum of minimum gap = " << missing(arr, n ,h);
    return 0;
}