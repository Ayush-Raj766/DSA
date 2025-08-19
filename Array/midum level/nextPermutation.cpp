#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int idx=-1;
    for(int i=n-2; i>=0;i--){
        if(arr[i]<arr[i+1]){
            idx = i ;
            break;
        }
    }
    if(idx==-1){
        reverse(arr.begin(), arr.end());
    }

    for(int i =n-1 ; i>idx;i++){
        if(arr[idx]<arr[i]){
            swap(arr[idx] , arr[i]);
            break;
        }
    }

    reverse(arr.begin()+idx+1 , arr.end());

        for(auto &i : arr) {
            cout << i << " ";
        }
        cout << endl;

    return 0;
}