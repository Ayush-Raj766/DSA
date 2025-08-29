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
    int row = 0;
    int col = m-1;
    bool found = false;

    while(row <n && col>=0){
        if(matrix[row][col] == x){
            found = true;
            break;
        }
        else if(matrix[row][col] > x){
            col--;
        }
        else{
            row++;
            // col = m-1;
        }
    }
    cout<<"found = "<<found;
    
    return 0;
}