#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m ,x;
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
    cout<<"target =";
    cin>>x;
    int l = 0;
    int r = n*m - 1;
    bool found = false;
    while(r>=l){
        int mid = (l+r)/2;
        int row = mid/m;
        int col = mid % m;
        if(matrix[row][col] == x){
            found = true;
            break;
        }
        else if(matrix[row][col] > x){
            r = mid -1;
        }
        else{
            l =mid +1;
        }
    }
    cout<<"found = "<<found;
    return 0;
}