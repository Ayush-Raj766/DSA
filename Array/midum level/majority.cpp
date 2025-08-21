#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout<<"enter size of array = ";
    cin>>n;
    int arr[n];
    for(int i =0 ; i<n ;i++){
        cin>>arr[i];
    }
    int count =0;
    int element;
    for(int i =0 ; i<n ; i++){
        if(count==0){
            count =1;
            element = arr[i];
        }
        else if(element ==arr[i]){
            count++;
        }
        else{
            count--;
        }
    }
    // cout<<"element is : "<<element<<endl;
    int count1 = 0 ;
    for(int i =0 ; i<n ;i++){
        if(element == arr[i]){
            count1++;
            // cout<<"count1 is "<<count1<<endl;
        }
    }

    if(count1 >=(n/3)){
        cout<<count1;
    }
    else{
        cout<<"no result";
    }
    return 0;
}