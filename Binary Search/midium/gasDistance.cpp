#include<bits/stdc++.h>
using namespace std;

bool placed(vector<int>&arr , int n , int h , double k){
    int req =0;
    for(int i=0 ; i<n-1 ; i++){
        double gap = arr[i+1] -arr[i];
        if(gap > k){
            req += ceil(gap/k) - 1;
        }
        if(req > h){
            return false;
        }
    }
    return true;
}

double gasStation(vector<int>&arr , int n , int h){
    double l = 0.0;
double r =arr[n-1] -arr[0];
    while ((r-l)>=1e-6){
    double mid = (l+r)/2.0;
    if(placed(arr , n , h , mid) == true){
        r = mid;
    }
    else {
        l = mid ;
    }
}
return r;

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
    cout<<"nor of gas will set between =";
    cin>> h;
    

    cout << "maximum of minimum gap = " << gasStation(arr, n ,h);
    return 0;
}