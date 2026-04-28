#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

int MinimumEffort(vector<vector<int>>& heights){
    int m = heights.size();
    int n = heights[0].size();

    vector<vector<int>> dist(m , vector<int>(n , 1e9));
    dist[0][0] = 0;
    priority_queue<pair<int , pair<int , int>> , vector<pair<int , pair<int , int>>> , greater<pair<int , pair<int , int>>>> pq;
    pq.push({0 , {0 , 0}});

    int dr[] ={-1 , 0 , 1 , 0};
    int dc[] ={0 , 1 , 0 , -1};

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int diff = it.first;
        int r = it.second.first;
        int c = it.second.second;

        for(int i = 0 ; i < 4 ; i++){
            int newr = r + dr[i];
            int newc = c + dc[i];

            if(newr >= 0 && newr < m && newc >= 0 && newc < n){
                int newDiff = max(diff , abs(heights[r][c] - heights[newr][newc]));
                if(newDiff < dist[newr][newc]){
                    dist[newr][newc] = newDiff;
                    pq.push({newDiff , {newr , newc}});
                }
            }
        }
    }

    return dist[m-1][n-1];

}

};

int main() {
     // Input grid (heights)
    vector<vector<int>> heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};

    Solution obj;

    // Find the minimum effort path
    int ans = obj.MinimumEffort(heights);

    // Output the result
    cout << ans << endl;
    return 0;
}