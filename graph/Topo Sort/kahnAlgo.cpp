#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
 vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> indegree(V, 0);
        for(int i = 0 ; i < V ; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i = 0 ; i < V ; i++){
            if(indegree[i] == 0 ){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it :adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        return ans;
 }

};

int main() {
     // Number of vertices and edges
    int V = 6, E = 6;

    // Adjacency list representation of the graph
    vector<int> adj[V];
    adj[5].push_back(0);
    adj[5].push_back(2);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    // Create an object of Solution
    Solution obj;

    // Get the topological order
    vector<int> res = obj.topoSort(V, adj);

    // Print the result
    cout << "Topological Sort: ";
    for (auto it : res) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}