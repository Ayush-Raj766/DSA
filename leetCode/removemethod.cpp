#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n + 1);
        // vector<int> indegree(n + 1, 0);
        for (const auto& invocation : invocations) {
            int u = invocation[0];
            int v = invocation[1];
            adj[u].push_back(v);
            // indegree[v]++;
        }
        
        vector<bool> visited(n + 1, false);
        dfs(k, adj, visited);
         for (auto &e : invocations) {
            int u = e[0];
            int v = e[1];

            if (!visited[u] && visited[v]) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }

        // Return all non-suspicious methods
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!visited[i])
                ans.push_back(i);
        }

        return ans;
        
    
        
    }
};

int main() {
    Solution sol;
    int n = 6;
int k = 2;

vector<vector<int>> invocations = {
    {2,3},
    {3,5},
    {2,4}
};
    vector<int> result = sol.remainingMethods(n, k, invocations);
    for (int method : result) {
        cout << method << " ";
    }
    return 0;
}