#include<bits/stdc++.h>
using namespace std;

int single(int arr[] , int n){
    int result = 0;
    for(int i =0 ; i < n ; i++){
        result = result ^ arr[i];
        cout << result <<endl;
    }
    return result;
}

int main() {
    int arr[]={1 , 5 , 2 ,1 ,2 ,9 ,7 ,9 ,7};

     int n = sizeof(arr) / sizeof(arr[0]);

    cout << "single num = " << single(arr, n);
    return 0;
}