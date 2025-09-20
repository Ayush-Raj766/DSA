#include<bits/stdc++.h>
using namespace std;


set<vector<int>> uniqueSet;
void subSequenceSum(vector<int> &arr , int i , int sum , vector<int> result , int k){
    if(sum >k) return;
    if(i == arr.size()){
        
        if(sum == k){
            
            sort(result.begin(), result.end());
            uniqueSet.insert(result);
        }
        return;
    }
    // sum += arr[i];
    result.push_back(arr[i]);
    subSequenceSum(arr , i+1 , sum + arr[i], result , k);
    // sum -= arr[i];
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
    for(auto it : uniqueSet){
        cout<<"[ ";
        for(auto i : it){
            cout<<i<<" ";
        }
        cout<<"]";
        cout<<endl;
    }
    return 0;
}