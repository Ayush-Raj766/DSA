#include<bits/stdc++.h>
using namespace std;

class Solution{

    public:

    int shortestPath(vector<vector<int>>& grid , pair<int , int> source , pair<int,int> destination){

        if(source == destination) return 0;

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist( m , vector<int>(n , 1e9));
        dist[source.first][source.second] = 0;
        queue<pair<int, pair<int, int>>> q;
        q.push({0 , {source.first , source.second}});

        int dr[] ={-1 , 0 , 1 , 0 , -1 , -1 , 1 , 1};
        int dc[] ={0 , 1 , 0 , -1 , -1 , 1 , -1 , 1};

        while(!q.empty()){
            auto it =q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            for(int i = 0 ; i < 8 ; i++){
                int newr = r + dr[i];
                int newc = c + dc[i];

                if(newr >= 0 && newr < m && newc >= 0 && newc < n && grid[newr][newc] == 1 && dis + 1 < dist[newr][newc]){
                    dist[newr][newc] = dis + 1;
                    if(make_pair(newr , newc) == destination) return dis + 1;
                    q.push({dis + 1 , {newr , newc}});
                }
            }
        }
        return -1;
    }
};

int main() {
    pair<int, int> source = {0, 1};
    pair<int, int> destination = {2, 2};

    // Define the grid
    vector<vector<int>> grid = {{1, 1, 1, 1},
                                 {1, 1, 0, 1},
                                 {1, 1, 1, 1},
                                 {1, 1, 0, 0},
                                 {1, 0, 0, 1}};

    Solution obj;

    // Call the method to find the shortest path
    int res = obj.shortestPath(grid, source, destination);

    // Output the result
    cout << res << endl;

    return 0;
}