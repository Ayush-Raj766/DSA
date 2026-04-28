#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S){
        priority_queue<pair<int ,int> ,vector<pair<int , int>> , greater<pair<int , int>>> pq;
        vector<int> dist(V , 1e9);
        dist[S] = 0;
        pq.push({0 , S});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int dis = it.first;
            for(auto it : adj[node]){
                int adjnode = it[0];
                int edw = it[1];
                if(dis + edw < dist[adjnode]){
                    dist[adjnode] = dis + edw;
                    pq.push({dis + edw , adjnode});
                }
            }
        }
        return dist;
    }
};
int main() {
    // Driver code.
    int V = 3, E = 3, S = 2;  // Number of vertices, edges, and source vertex
    vector<vector<int>> adj[V]; // Adjacency list representation of the graph

    // Example graph with edges and weights
    vector<int> v1{1, 1}, v2{2, 6}, v3{2, 3}, v4{0, 1}, v5{1, 3}, v6{0, 6};
    adj[0].push_back(v1);
    adj[0].push_back(v2);
    adj[1].push_back(v3);
    adj[1].push_back(v4);
    adj[2].push_back(v5);
    adj[2].push_back(v6);

    Solution obj;
    // Call dijkstra function and store the result
    vector<int> res = obj.dijkstra(V, adj, S);

    // Output the shortest distance from source to all nodes
    for (int i = 0; i < V; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}