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
    int left = 0 , right = m-1 , top =0, bottum = n-1;
    while (top <= bottum && left <= right){
        for(int i =left ; i<=right ;i++){
            cout<<arr[top][i]<<" ";
        }
        top++;
        for(int i =top ; i<=bottum ;i++){
            cout<<arr[i][right]<<" ";
        }
        right--;
        for(int i = right ; i>=left ;i--){
            cout<<arr[bottum][i]<<" ";
        }
        bottum--;
        for(int i = bottum ; i>=top ;i--){
            cout<<arr[i][left]<<" ";
        }
        left++;
    }

    return 0;
}