#include<bits/stdc++.h>
using namespace std;

int sums(vector<int> &arr , int n , int x){
    int countstudent = 1;
    int totalPages =0;
    for(int i =0 ;i<n ; i++){
        if(totalPages + arr[i] <= x){
            totalPages += arr[i];
            // countstudent++;
        }
        else{
            totalPages = arr[i];
            countstudent++;
        }
    }
    return countstudent;
}

int split(vector<int> &arr , int n , int h){
    int l =*max_element(arr.begin() , arr.end());
    int r = accumulate(arr.begin() ,arr.end() ,0);

    int res;
    while(r>=l){
        int mid = (l+r)/2;


        if(sums(arr,n,mid) <=h){
            r = mid -1;
            // res =mid+1;
        }
        else{
            l=mid+1;
            
        }
    }
    return l;
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
    cout<<"nor of split =";
    cin>> h;
    

    cout << "minimum  of maximum book pages = " << split(arr, n ,h);
    return 0;
}