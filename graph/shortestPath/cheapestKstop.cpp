#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    vector<pair<int , int>> adj[n];
    for(auto it : flights){
        adj[it[0]].push_back({it[1] , it[2]});
        // adj[it[1]].push_back({it[0] , it[2]});
    }
    vector<int> dist(n , 1e9);
    dist[src] = 0;
    queue<pair<int , pair<int , int>>> pq;
    pq.push({0 , {src , 0}});

    while(!pq.empty()){
        auto it = pq.front();
        pq.pop();
        int stops = it.first;
        int node = it.second.first;
        int cost = it.second.second;

        if(stops > K) continue;

        for(auto it : adj[node]){
            int adjNode = it.first;
            int x = it.second;
            if(cost + x < dist[adjNode]){
                dist[adjNode] = cost + x;
                pq.push({stops + 1 , {adjNode , cost + x}});
            }
        }
    }
    return dist[dst] == 1e9 ? -1 : dist[dst];
}
};

int main() {
       int n = 4, src = 0, dst = 3, K = 1;

    // Flight routes and their costs
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600},
    {2, 3, 200}};

    Solution obj;

    // Call the method to find the cheapest flight
    int ans = obj.CheapestFLight(n, flights, src, dst, K);

    // Output the result
    cout << ans << endl;

    return 0;
}