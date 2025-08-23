#include<bits/stdc++.h>
using namespace std;


long long count2 =0;
void join(int arr[] , int l , int mid , int r){
    int n1=mid-l+1;
    int n2 = r-mid;

    int a[n1];
    int b[n2];

    for(int i=0 ; i<n1 ; i++){
        a[i] = arr[l+i];
    }

    for(int i=0 ; i<n2 ; i++){
        b[i] = arr[mid+1+i];
    }
    int x = 0;
    for (int i = 0; i < n1; i++) {
        while (x < n2 && a[i] > 2* b[x]) {
            x++;
        }
        count2 += x;  // all b[0..j-1] are valid for this a[i]
    }
    int i =0 ;
   int  j = 0;
    int k=l;
    

    while(i<n1 && j<n2){
        if(a[i] <= b[j]){
            arr[k] = a[i];
            i++;
            k++;
            
        }
        else {
            arr[k] = b[j];
            j++;
            k++;
     
        }
    }
    while(i<n1){
        arr[k] = a[i];
        i++;
        k++;
    }

    while(j<n2){
        arr[k] = b[j];
        j++;
        k++;
        
    }

}

void div(int arr[] ,  int l , int r){
    if(l < r){
        int mid = (l+r) / 2;
        div(arr , l ,mid);
        div(arr , mid+1 , r);

        join(arr , l , mid ,r);

    }
}

int main() {
    int n;
    cout<<"enter the size = ";
    cin>>n;
    int arr[n];
    cout<<"array = ";
    for(int i =0 ; i<n ; i++){
        cin>>arr[i];
    }

    div(arr , 0 , n-1);

    cout<<"inverse count ="<<count2;

    return 0;
}


