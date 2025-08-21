#include<bits/stdc++.h>
using namespace std;

int main() {
    int n , m;
    cout<<"enter nor of row = ";
    cin>> n;
    cout<<"enter nor of col = ";
    cin>> m;
    int arr[n][m];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout<<"enter element at position ["<<i<<"]["<<j<<"] = ";
            cin>> arr[i][j];
        }
        cout<<endl;
    }

    int row[n];
    int col[m] ;
    row[n]={0};
    col[m] ={0};
    for(int i = 0 ; i<n ;i++){
        for(int j = 0 ; j<m ;j++){
            if(arr[i][j] ==0){
                row[i]=1;
                col[j]=1;
            }

        }
    }
    for(int i = 0 ; i<n ;i++){
        for(int j = 0 ; j<m ;j++){
            if(row[i] == 1 || col[j] == 1){
                arr[i][j] = 0;
            }
        }
    }
    cout<<"The modified matrix is : "<<endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout<< arr[i][j] <<" ";
        }
        cout<<endl;
    }

    
    return 0;
}