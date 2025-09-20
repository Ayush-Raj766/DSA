#include<bits/stdc++.h>
using namespace std;

set<vector<int>> uniqueSet;

void subSequenceSum(vector<int> &arr , int i , int sum , vector<int> result ){
    if(i == arr.size()){
        sort(result.begin(), result.end());
        uniqueSet.insert(result);
        return;
    }
    // sum += arr[i];
    result.push_back(arr[i]);
    subSequenceSum(arr , i +1, sum + arr[i], result);
    // sum -= arr[i];
    result.pop_back();
    subSequenceSum(arr , i+1 , sum , result);
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

    subSequenceSum(arr, 0, 0, {});
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