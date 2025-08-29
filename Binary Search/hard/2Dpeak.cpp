#include<bits/stdc++.h>
using namespace std;

int rowIndex(vector<vector<int>> &matrix, int n, int mid){
    int maxrow = 0;
    for( int i =0 ;i<n; i++){
        if(matrix[i][mid]>matrix[maxrow][mid]){
            maxrow = i;
        }
    }
    return maxrow;
}

int peakElement(vector<vector<int>> &matrix, int n, int m)
{
    int l = 0;
    int r = m-1;

    while(r>=l){
        int mid = (l+r)/2;
        int row =rowIndex(matrix, n, mid);

        int left ;
        if(mid-1>=0){
            left = matrix[row][mid-1];
        }
        else{
            left =-1;
        }
        int right;
        if(mid+1<m){
            right = matrix[row][mid+1];
        }
        else{
            right = -1;
        }
        if(matrix[row][mid]>left && matrix[row][mid]>right){
            return matrix[row][mid];
        }
        else if(left>right){
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return -1;
}

int main() {
    int n, m;
    cout << "enter number of row";
    cin >> n;
    cout << "enter number of columns";
    cin >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    cout << "enter elements of matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    // peakElement(matrix, n, m);
    cout<<"output = "<<peakElement(matrix, n, m)<<endl;
    return 0;
}