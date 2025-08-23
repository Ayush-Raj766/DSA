#include<bits/stdc++.h>
using namespace std;

void input(int arr[] , int n){
    for(int i =0 ;i<n ;i++){
        cin>>arr[i];
    }
}

void output(int arr[] , int n){
    for(int i =0 ;i<n ;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int n ,m ;
    cout<<"enter nor of elements in arrays = ";
    cin>>n>>m;
    int arr1[n] , arr2[m];

    cout<<"first array  = ";
    input(arr1 , n);

    cout<<"second array  = ";
    input(arr2 , m);

    int a=0 , b=0;

    int p = max(n , m);
    for(int i =0 ; i<p ;i++){
        if(arr1[a]<arr2[b]){
            a++;
        }
        else if(arr1[a] > arr2[b]){
            sort(arr2 , arr2 + m);
            swap(arr1[a] , arr2[b]);
            a++;
        }
        
    }

    if(arr1[n-1] > arr2[0]){
        swap(arr1[n-1] , arr2[0]);
    }

     cout<<"first array  = ";
    output(arr1 , n);

    cout<<"second array  = ";
    sort(arr2, arr2+m);
    output(arr2 , m);

    return 0;
}