#include<bits/stdc++.h>
using namespace std;


set<vector<int>> uniqueSet;
void subSequenceSum(vector<int> &arr , int i , int sum , vector<int> result , int k , int size){
    if(sum >k) return;
    if(i == arr.size()){
        
        if(sum == k && result.size() == size){
            
            sort(result.begin(), result.end());
            uniqueSet.insert(result);
        }
        return;
    }
    // sum += arr[i];
    result.push_back(arr[i]);
    subSequenceSum(arr , i+1 , sum + arr[i], result , k , size);
    // sum -= arr[i];
    result.pop_back();
    subSequenceSum(arr , i+1 , sum , result , k , size);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout<<"size of subsequence: ";
    int size;
    cin>>size;
    int k ;
    cout<<"enter the sum: ";
    cin>>k;
    cout<<"the subsequence sums are: ";
    vector<int> result;
    subSequenceSum(arr, 0, 0, result , k , size);
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