#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> matrix(n, vector<int>(n, 1e9));

        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            matrix[u][v] = w;
            matrix[v][u] = w;
        }

        for(int i = 0; i < n; i++){
            matrix[i][i] = 0;
        }

        // Floyd Warshall
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(matrix[i][k] != 1e9 && matrix[k][j] != 1e9){
                        matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                    }
                }
            }
        }

        int ans = -1;
        int minCount = 1e9;

        for(int i = 0; i < n; i++){
            int count = 0;
            for(int j = 0; j < n; j++){
                if(i != j && matrix[i][j] <= distanceThreshold){
                    count++;
                }
            }

            if(count <= minCount){
                minCount = count;
                ans = i;
            }
        }

        return ans;
    }
};
int main() {
     int n = 4;
    int m = 4;
    vector<vector<int>> edges = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
    int distanceThreshold = 4;

    // Create an object of the Solution class
    Solution obj;

    // Find the city with the least reachable cities within the threshold distance
    int cityNo = obj.findCity(n, m, edges, distanceThreshold);

    // Output the result
    cout << "The answer is node: " << cityNo << endl;
    return 0;
}