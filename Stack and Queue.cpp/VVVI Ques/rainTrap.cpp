#include<bits/stdc++.h>
using namespace std;

int trap(vector <int> &arr){
    int n =arr.size();
    int prifixsum[n] , sufixsum[n];
    prifixsum [0] =  arr[0];
    for(int i =1;i<n;i++){
        prifixsum[i] = max(prifixsum[i-1] , arr[i]);
    }
    sufixsum [n-1] =  arr[n-1];
    for(int i =n-2;i>=0;i--){
        sufixsum[i] = max(sufixsum[i+1] , arr[i]);
    }
    int res=0;
    for(int i = 0 ; i<n ;i++){
        res += min(prifixsum[i] , sufixsum[i])-arr[i];
    }
    return res;

}

int main() {
    vector < int > arr;
  arr = {0,1,0,2,1,0,1,3,2,1,2,1};
  cout << "The water that can be trapped is " << trap(arr) << endl;
    return 0;
}