#include<bits/stdc++.h>
using namespace std;

class Solution {
    public: 
    void bfs(vector<int> adjlist[], int start, vector<int>& vis){
        queue<int> q; 
        q.push(start);
        vis[start] = 1;
        while(!q.empty()){
            int node =q.front();
            q.pop();
            for(auto it : adjlist[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }
    int countComponents(int n , vector<vector<int>>& edges){
        vector<int> adjlist[n];
        for(auto it : edges){
            adjlist[it[0]].push_back(it[1]);
            adjlist[it[1]].push_back(it[0]);
        }

        vector<int> vis(n,0);
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                count++;
                bfs(adjlist, i, vis);
            }
        }
        return count;
    }
};

int main() {
     int V = 5;

    // List of undirected edges
    vector<vector<int>> edges = {{0,1},{1,2},{3,4}};

    // Create solution object
    Solution sol;

    // Print the number of connected components
    cout << "Number of Connected Components: " 
         << sol.countComponents(V, edges) << endl;

    return 0;
}