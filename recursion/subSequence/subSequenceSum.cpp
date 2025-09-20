#include<bits/stdc++.h>
using namespace std;

void subSequenceSum(vector<int> &arr , int i , int sum , vector<int> result , int k){
    if(i == arr.size()){
        if(sum == k){
            cout<<"[ ";
            for(auto it : result){
                cout<<it<<" ";
            }
            cout<<"]";
            cout<<endl;
        }
        return;
    }
    sum += arr[i];
    result.push_back(arr[i]);
    subSequenceSum(arr , i+1 , sum , result , k);
    sum -= arr[i];
    result.pop_back();
    subSequenceSum(arr , i+1 , sum , result , k);
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
    int k ;
    cout<<"enter the sum: ";;
    cin>>k;
    cout<<"the subsequence sums are: ";
    vector<int> result;
    subSequenceSum(arr, 0, 0, result , k);
    return 0;
}