#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(int node , vector<vector<int>>& adj , vector<bool>&vis , int &nodes , int &edgesCount){
        vis[node] = true;
        nodes++;
        edgesCount += adj[node].size();
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it , adj , vis , nodes , edgesCount);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int count = 0;
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int nodes = 0, edgesCount = 0;
                dfs(i, adj, vis, nodes, edgesCount);
                
                if (edgesCount == nodes * (nodes - 1)) {
                    count++;
                }

            }
        }
        return count;
    }
};

int main() {
    int n = 8;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 7}, {3, 6}};
    Solution sol;
    int result = sol.countCompleteComponents(n, edges);
    cout << "Number of complete components: " << result << endl;
    
    return 0;
}