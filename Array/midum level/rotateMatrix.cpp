#include<bits/stdc++.h>
using namespace std;

int main() {
      int n , m;
    cout<<"enter nor of row = ";
    cin>> n;
    
    vector <vector<int>> arr(n , vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout<<"enter element at position ["<<i<<"]["<<j<<"] = ";
            cin>>arr[i][j];
        }
        cout<<endl;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            swap(arr[i][j],arr[j][i]);
        }
    }

    for(int i = 0 ; i<n;i++){
        reverse(arr[i].begin() , arr[i].end());
    }

    cout<<"The modified matrix is : "<<endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout<< arr[i][j] <<" ";
        }
        cout<<endl;
    }

    return 0;
}