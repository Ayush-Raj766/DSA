#include<bits/stdc++.h>
using namespace std;

bool subSequenceSum(vector<int> &arr , int i , int sum ,  int k){
    if(i == arr.size()){
        if(sum == k){
            return true;
        }
        return false;
    }
    sum += arr[i];
    if(subSequenceSum(arr , i+1 , sum , k)){
        return true;
    }
    sum -= arr[i];
    return subSequenceSum(arr , i+1 , sum ,  k);
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
    bool found = subSequenceSum(arr, 0, 0, k);

    if (!found){
        cout << "No subsequence found!" << endl;
    }
    else{
        cout << "Subsequence found!" << endl;
    }
    return 0;
}