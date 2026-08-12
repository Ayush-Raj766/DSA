#include<bits/stdc++.h>
using namespace std;
class Solution{
    private:

    void dfs(int node , int &time , vector<int> &disc, vector<int> &low, vector<int> &parent, vector<vector<int>> &adj, vector<vector<int>> &bridges){
        disc[node] = low[node] = time++;
        for(auto it : adj[node]){
            if(disc[it] == -1){
                parent[it] = node;
                dfs(it, time , disc , low , parent , adj , bridges);
                low[node] = min(low[node], low[it]);
                if(low[it] > disc[node]){
                    bridges.push_back({node, it});
                }

            }
                  else if(it != parent[node]) {
                low[node] = min(low[node], disc[it]);
            }
        }
    }

    public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections){
        vector<vector<int>> adj(n);
        for(auto it : connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> disc(n, -1);
        vector<int> low(n, -1);
        vector<int> parent(n, -1);
        vector<vector<int>> bridges;
        int time = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(disc[i] == -1){
                dfs(i,time,disc,low,parent,adj,bridges);
            }
        }
        return bridges;
    }


};

int main() {
    int n = 4;
    vector<vector<int>> connections = {
        {0, 1}, {1, 2}, {2, 0}, {1, 3}
    };

    Solution obj;
    vector<vector<int>> bridges = obj.criticalConnections(n, connections);

    cout << "Critical Connections (Bridges): ";
    for (auto it : bridges) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}