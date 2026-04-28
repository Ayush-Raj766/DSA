#include<bits/stdc++.h>
using namespace std;

int largestSubmatrix(vector<vector<int>> matrix){
    int m = matrix.size();
    int n =  matrix[0].size();
    int maxArea = 0 ;
    for(int i = 0 ; i < m ; i++){
        if(i > 0){
            for(int j = 0 ; j < n ; j++){
                if(matrix[i][j] == 1 ){
                    matrix[i][j] += matrix[i-1][j];
                }
            }
        }
         vector<int> row = matrix[i];
        sort(row.begin(), row.end(), greater<int>());

        for(int j = 0 ; j < n ; j++){
            int area = row[j] * row[j+1];
            maxArea = max(area , maxArea);
        }
    }

    return maxArea;

}

int main() {
     int m, n;
    cout << "Enter rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    cout << "Enter matrix elements (0 or 1):" << endl;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int result = largestSubmatrix(matrix);

    cout << "Largest submatrix area with all 1s: " << result << endl;

    return 0;
}