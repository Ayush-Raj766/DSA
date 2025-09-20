#include<bits/stdc++.h>
using namespace std;

void subSequenceSum(vector<int> &arr , int i , int sum ){
    if(i == arr.size()){
        cout<<sum<<" ";
        return;
    }
    // sum += arr[i];
    // result.push_back(arr[i]);
    subSequenceSum(arr , i +1, sum + arr[i]);
    // sum -= arr[i];
    // result.pop_back();
    subSequenceSum(arr , i+1 , sum );
}

int main() {
    int n;
    cout<<"enter the number of elements: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"enter the elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    subSequenceSum(arr, 0, 0);
    return 0;
}