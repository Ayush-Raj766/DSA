#include<bits/stdc++.h>
using namespace std;

class Solution {
    public: 
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int low = 0 , high = n * n - 1;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

        vector<vector<int>> vis(n, vector<int>(n, 0));

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        minHeap.push({grid[0][0], 0, 0});
        vis[0][0] = 1;

        while(!minHeap.empty()){
            auto curr = minHeap.top();
            minHeap.pop();

            int time = curr[0];
            int r = curr[1];
            int c = curr[2];

            if(r == n-1 && c == n-1 ) return time;
            for (int i = 0 ; i < 4 ; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < n && !vis[nr][nc]){
                    vis[nr][nc] = 1;
                    minHeap.push({max(time, grid[nr][nc]), nr, nc});

                }

            }
            
        }
        return -1;

    }
};

int main() {
    vector<vector<int>> grid = {{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}};
    Solution sol;
    cout << "Minimum time to reach destination: " << sol.swimInWater(grid) << endl;
    return 0;
}