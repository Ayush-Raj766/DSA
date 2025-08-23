#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout<<"enter the size = ";
    cin>>n;
    int sn = n*(n+1)/2;
    int s2n = n*(n+1)*(2*n+1)/6;
    // cout<<"sn = "<<sn<<"s2n = "<<s2n<<endl;
    int arr[n];
    cout<<"array = ";
    for(int i =0 ; i<n ; i++){
        cin>>arr[i];
    }

    int sum = 0;
    int sum2 = 0;
    for(int i = 0 ;i<n ;i++){
        sum = sum + arr[i];
        sum2 = sum2 + arr[i] * arr[i];
    }
    int x = (sum2-s2n)/(sum-sn);
    // cout<<"x = "<<x<<endl;

    int res = (x + (sum - sn))/2;
    cout<< res<<endl;
    cout<<x-res<<endl;
    return 0;
}